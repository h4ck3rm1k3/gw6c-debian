/*
---------------------------------------------------------------------------
 $Id: version.c,v 1.3 2005/06/07 21:16:42 dgregoire Exp $
---------------------------------------------------------------------------
  Copyright (c) 2001-2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT
---------------------------------------------------------------------------
*/

#include "platform.h"

#include "version.h"

char *tsp_get_version(void) {
  return IDENTIFICATION;
}
