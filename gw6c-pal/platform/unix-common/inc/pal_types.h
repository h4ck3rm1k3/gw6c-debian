/*
-----------------------------------------------------------------------------
 $Id: pal_types.h,v 1.3 2007/10/19 18:18:05 cnepveu Exp $
-----------------------------------------------------------------------------
Copyright (c) 2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT
-----------------------------------------------------------------------------

  Platform abstraction layer for various type definitions.

-----------------------------------------------------------------------------
*/
#ifndef __PAL_TYPES_H__
#define __PAL_TYPES_H__


// Definitions
#undef NULL
#define NULL            (0)

/* Causes conflicts on OpenBSD
// Length type definitions
typedef unsigned int    size_t;
typedef signed int      ssize_t;
*/

// Pointer type defintion
typedef unsigned int    ptr_t;

// Integer type definitions
typedef unsigned int    uint32_t;
typedef signed int      sint32_t;
typedef unsigned short  uint16_t;
typedef signed short    sint16_t;
typedef unsigned char   uint8_t;
typedef signed char     sint8_t;


#endif
