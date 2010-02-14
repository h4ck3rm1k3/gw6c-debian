/*
-----------------------------------------------------------------------------
 $Id: pal_getopt.h,v 1.1 2007/10/17 15:33:24 cnepveu Exp $
-----------------------------------------------------------------------------
Copyright (c) 2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT
-----------------------------------------------------------------------------

  Platform abstraction layer for 'getopt'.

-----------------------------------------------------------------------------
*/
#ifndef __PAL_GETOPT_H__
#define __PAL_GETOPT_H__

// getopt API definition.
#include "pal_getopt.def"

// getopt function already available in this platform.
#undef pal_getopt
#define pal_getopt getopt

#endif
