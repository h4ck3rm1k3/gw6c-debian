/*
-----------------------------------------------------------------------------
 $Id: pal_criticalsection.h,v 1.2 2007/10/25 14:21:04 cnepveu Exp $
-----------------------------------------------------------------------------
Copyright (c) 2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT
-----------------------------------------------------------------------------

  Platform abstraction layer critical section definitions.

-----------------------------------------------------------------------------
*/
#ifndef __PAL_CRITICALSECTION_H__
#define __PAL_CRITICALSECTION_H__


#include <pthread.h>
typedef pthread_mutex_t pal_cs_t;


// Critical section API definitions.
#include "pal_criticalsection.def"


// Critical section functions already available in this platform.
#undef pal_init_cs
#define pal_init_cs(X) pthread_mutex_init(X, NULL)

#undef pal_enter_cs
#define pal_enter_cs   pthread_mutex_lock

#undef pal_leave_cs
#define pal_leave_cs   pthread_mutex_unlock

#undef pal_free_cs
#define pal_free_cs    pthread_mutex_destroy

#endif
