/*
-----------------------------------------------------------------------------
 $Id: pal_version.h,v 1.2 2007/10/17 15:36:34 cnepveu Exp $
-----------------------------------------------------------------------------
Copyright (c) 2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT
-----------------------------------------------------------------------------

  Platform abstraction layer version.

-----------------------------------------------------------------------------
*/
#ifndef __PAL_VERSION_H__
#define __PAL_VERSION_H__


#ifndef PLATFORM
#define PLATFORM "Unknown platform"
#endif

const char* get_pal_version( void );

#endif
