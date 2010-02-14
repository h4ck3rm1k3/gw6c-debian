/*
---------------------------------------------------------------------------
 $Id: tsp_tun.h,v 1.5 2008/03/14 19:47:38 cnepveu Exp $
---------------------------------------------------------------------------
Copyright (c) 2001-2006 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT
  
---------------------------------------------------------------------------
*/

#ifndef TUN_H
#define TUN_H

#include "config.h"   // tBoolean

void                TunName               ( int tunfd, char* name, size_t name_len );
int                 TunInit               (char* name);
gw6c_status         TunMainLoop           (int tun, int Socket, tBoolean keepalive,
                                           int keepalive_interval, char *local_address_ipv6,
                                           char *keepalive_address);

#endif /* TUN_H */
