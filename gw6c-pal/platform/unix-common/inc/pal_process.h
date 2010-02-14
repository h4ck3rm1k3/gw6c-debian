/*
-----------------------------------------------------------------------------
 $Id: pal_process.h,v 1.3 2008/02/27 14:55:30 cnepveu Exp $
-----------------------------------------------------------------------------
Copyright (c) 2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT
-----------------------------------------------------------------------------

  Platform abstraction layer process definitions.

-----------------------------------------------------------------------------
*/
#ifndef __PAL_PROCESS_H__
#define __PAL_PROCESS_H__


// process API definitions.
#include "pal_process.def"
#include <unistd.h>


// process functions already available in this platform.
#undef pal_getpid
#define pal_getpid getpid

#undef pal_getppid
#define pal_getppid getppid

#endif
