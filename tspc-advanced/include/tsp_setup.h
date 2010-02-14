/*
-----------------------------------------------------------------------------
 $Id: tsp_setup.h,v 1.8 2008/03/13 19:52:12 cnepveu Exp $
-----------------------------------------------------------------------------
  Copyright (c) 2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT.
-----------------------------------------------------------------------------
*/

#ifndef _TSP_SETUP_H_
#define _TSP_SETUP_H_

#include "config.h"
#include "xml_tun.h"

sint32_t            execScript            ( const char *cmd );
gw6c_status         tspSetupInterface     ( tConf *c, tTunnel *t );
gw6c_status         tspTearDownTunnel     ( tConf* pConf, tTunnel* pTunInfo );

#endif
