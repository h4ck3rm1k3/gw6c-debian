/*
-----------------------------------------------------------------------------
 $Id: console.h,v 1.2 2008/01/09 15:08:45 cnepveu Exp $
-----------------------------------------------------------------------------
Copyright (c) 2001-2006 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT.
-----------------------------------------------------------------------------
*/

#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#if !defined(WINCE)
sint32_t            enable_console_input  (void);
sint32_t            disable_console_input (void);
#endif

#endif
