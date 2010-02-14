/*
-----------------------------------------------------------------------------
 $Id: tsp_tun.h,v 1.11 2008/03/13 19:52:16 cnepveu Exp $
-----------------------------------------------------------------------------
Copyright (c) 2001-2005 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT
  
-----------------------------------------------------------------------------
*/

#ifndef TUN_H
#define TUN_H

#include "config.h"   // tBoolean

void                TunName               ( int tunfd, char* name, size_t name_len );
int                 TunInit               (char *dont_care);
gw6c_status         TunMainLoop           (int tun, int Socket, tBoolean keepalive,
                                           int keepalive_interval, char *local_address_ipv6,
                                           char *keepalive_address);

#endif /* TUN_H */
