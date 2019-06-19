// ScanDepsPluginInterface - Interface for dependencies scan plugin

//------------------------------------------------------------------------------
#pragma once
#if _WIN32
    #define STDCALL __stdcall
#elif defined(__LINUX__) || defined(__OSX__)
    #define STDCALL
#else
    #error Unknown Platform
#endif

// DLL Export
//------------------------------------------------------------------------------
// Externally compiled DLL should define this appropriately
// e.g.
//#define SCANDEPSPLUGIN_DLL_EXPORT __declspec(dllexport)

#if !defined(_WIN32) //TODO:Windows : Use unmangled name on windows.
extern "C" {
#endif

typedef int ( STDCALL * ScanDepsMainFunc )( int argc, const char **argv );
#ifdef SCANDEPSPLUGIN_DLL_EXPORT
    SCANDEPSPLUGIN_DLL_EXPORT int main(int argc, const char **argv);
#endif

#if !defined(_WIN32)//TODO:Windows : Use unmangled name on windows.
} //extern "C"
#endif

//------------------------------------------------------------------------------
