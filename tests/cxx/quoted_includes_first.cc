//===--- quoted_includes_first.cc - test input file for iwyu --------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// Tests that IWYU will respect the --quoted_includes_first option.

#include "tests/cxx/pch.h"  // this is the precompiled header
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include "subfolder/indirect_subfolder.h"
#include "quoted_includes_first.h"

std::unique_ptr<IndirectSubfolderClass> CreateIndirectSubfolderClass() {
  return std::unique_ptr<IndirectSubfolderClass>(new IndirectSubfolderClass);
}

/**** IWYU_SUMMARY

tests/cxx/quoted_includes_first.cc should add these lines:

tests/cxx/quoted_includes_first.cc should remove these lines:
- #include <iostream>  // lines XX-XX
- #include <list>  // lines XX-XX
- #include <map>  // lines XX-XX

The full include-list for tests/cxx/quoted_includes_first.cc:
#include "tests/cxx/pch.h"
#include "quoted_includes_first.h"
#include "subfolder/indirect_subfolder.h"  // for IndirectSubfolderClass
#include <memory>  // for unique_ptr

***** IWYU_SUMMARY */
