/*
-----------------------------------------------------------------------------
 $Id: pal_unistd.c,v 1.2 2008/03/26 16:47:14 cnepveu Exp $
-----------------------------------------------------------------------------
Copyright (c) 2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT
-----------------------------------------------------------------------------

  Platform abstraction layer for unistd.

-----------------------------------------------------------------------------
*/

#include "pal_types.h"
#include "pal_unistd.h"

// --------------------------------------------------------------------------
// The implementation of usleep on NetBSD does not allow a
//   parameter >= 1000000(1 second) for input. So the sleep time is broken
//   in a call to sleep for the seconds, and then usleep for the remaining
//   milliseconds.
//
void pal_sleep( uint32_t sleep_ms )
{
  uint32_t seconds = sleep_ms / 1000;
  uint32_t miliseconds = sleep_ms % 1000;

  sleep(seconds);
  usleep(miliseconds * 1000); // microseconds.
}
