/*
-----------------------------------------------------------------------------
 $Id: xml_req.h,v 1.7 2008/01/09 15:08:47 cnepveu Exp $
-----------------------------------------------------------------------------
  Copyright (c) 2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT.
-----------------------------------------------------------------------------
*/

#ifndef _XML_REQ_H_
#define _XML_REQ_H_

#include "config.h"

char *              tspBuildCreateRequest ( tConf * );
char *              tspBuildCreateAcknowledge( void );

#endif
