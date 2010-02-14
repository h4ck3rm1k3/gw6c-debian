// **************************************************************************
// $Id: debugdefs.h,v 1.2 2007/01/30 18:53:26 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
// 
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Includes required header files to perform debug assertions and
//   defines compiltation conditionnal macros for debugging.
//
//   This header should only be included in module bodies(*.cc), not in
//   the interface(*.h).
//
//   * Make sure precompilation symbol  NDEBUG  is defined when compiling a
//   release version.
//
// Author: Charles Nepveu
//
// Creation Date: December 2006
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cmessaging_debugdefs_h__
#define __gw6cmessaging_debugdefs_h__


// The assert header should be included even when compiling with NDEBUG
#include <assert.h>


#ifndef NDEBUG
#include <iostream>
#include <iomanip>
using namespace std;
#define DBG_PRINT(X)      cout << X << endl;
#else
#define DBG_PRINT(X)
#endif


#endif
