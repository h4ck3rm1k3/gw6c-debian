/*
-----------------------------------------------------------------------------
 $Id: pal_unistd.h,v 1.4 2007/10/29 17:16:09 cnepveu Exp $
-----------------------------------------------------------------------------
Copyright (c) 2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT
-----------------------------------------------------------------------------

  Platform abstraction layer for unistd.

-----------------------------------------------------------------------------
*/
#ifndef __PAL_UNISTD_H__
#define __PAL_UNISTD_H__

// unistd API definitions.
#include "pal_unistd.def"
#include <unistd.h>


// unistd functions already available in this platform.
#undef pal_getcwd
#define pal_getcwd getcwd

#undef pal_chdir
#define pal_chdir chdir

#undef pal_sleep
#define pal_sleep(x) usleep((x) * 1000)

#undef pal_unlink
#define pal_unlink unlink


#endif
