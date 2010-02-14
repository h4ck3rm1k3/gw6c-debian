/*
-----------------------------------------------------------------------------
 $Id: pal_time.h,v 1.3 2007/10/26 15:28:46 cnepveu Exp $
-----------------------------------------------------------------------------
Copyright (c) 2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT
-----------------------------------------------------------------------------

  Platform abstraction layer time definitions.

-----------------------------------------------------------------------------
*/
#ifndef __PAL_TIME_H__
#define __PAL_TIME_H__


// time API definitions.
#include "pal_time.def"
#include <time.h>
#include <sys/time.h>


// time functions already available in this platform.
#undef pal_gettimeofday
#define pal_gettimeofday(X) gettimeofday(X, NULL)

#undef pal_localtime
#define pal_localtime localtime

#undef pal_time
#define pal_time time

#endif
