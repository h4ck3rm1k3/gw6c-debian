/*
-----------------------------------------------------------------------------
 $Id: pal_version.c,v 1.3 2007/10/17 16:18:58 cnepveu Exp $
-----------------------------------------------------------------------------
Copyright (c) 2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT
-----------------------------------------------------------------------------

  Platform abstraction layer version info.

-----------------------------------------------------------------------------
*/
#include "pal_version.h"

#define PAL_VER_STRING "Gateway6 Client PAL for " PLATFORM " built on " __DATE__

/*
  Returns the pal version.
*/
const char* get_pal_version( void )
{
  return PAL_VER_STRING;
}
