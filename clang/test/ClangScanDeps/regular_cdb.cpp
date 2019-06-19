// RUN: rm -rf %t.dir
// RUN: rm -rf %t.cdb
// RUN: mkdir -p %t.dir
// RUN: cp %s %t.dir/regular_cdb.cpp
// RUN: mkdir %t.dir/Inputs
// RUN: cp %S/Inputs/header.h %t.dir/Inputs/header.h
// RUN: sed -e "s|DIR|%/t.dir|g" %S/Inputs/regular_cdb.json > %t.cdb
// RUN: clang-scan-deps -compilation-database %t.cdb -j 1
// RUN: cat %t.dir/regular_cdb.d | FileCheck %s

#include "header.h"

// CHECK: regular_cdb.cpp
// CHECK-NEXT: Inputs{{/|\\}}header.h
