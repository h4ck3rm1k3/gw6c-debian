/*
---------------------------------------------------------------------------
 $Id: tsp_tun.h,v 1.9 2008/03/14 16:13:41 cnepveu Exp $
---------------------------------------------------------------------------
This source code copyright (c) Hexago Inc. 2002-2005.

  For license information refer to CLIENT-LICENSE.TXT
  
---------------------------------------------------------------------------
*/

#ifndef TUN_H
#define TUN_H

#include "config.h"

sint32_t            TunInit               (char *TunDevice);
gw6c_status         TunMainLoop           (sint32_t tunfd, pal_socket_t Socket, 
                                           tBoolean keepalive, sint32_t keepalive_interval,
		                                       char *local_address_ipv6, char *keepalive_address);

#endif /* TUN_H */
