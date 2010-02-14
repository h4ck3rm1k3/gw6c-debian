/*
-----------------------------------------------------------------------------
 $Id: net_tcp.h,v 1.10 2008/03/20 16:58:37 cnepveu Exp $
-----------------------------------------------------------------------------
  Copyright (c) 2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT.
-----------------------------------------------------------------------------
*/

#ifndef _NET_TCP_H_
#define _NET_TCP_H_

extern sint32_t     NetTCPConnect         (pal_socket_t *, char *, uint16_t );
extern sint32_t     NetTCPClose           (pal_socket_t);

extern sint32_t     NetTCPReadWrite       (pal_socket_t, char *, sint32_t, char *, sint32_t);

extern sint32_t     NetTCPWrite           (pal_socket_t, char *, sint32_t);
extern sint32_t     NetTCPPrintf          (pal_socket_t, char *, sint32_t, char *, ...);

extern sint32_t     NetTCPRead            (pal_socket_t, char *, sint32_t);

#endif
