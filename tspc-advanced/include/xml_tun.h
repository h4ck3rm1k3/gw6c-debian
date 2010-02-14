/*
-----------------------------------------------------------------------------
 $Id: xml_tun.h,v 1.10 2008/01/09 15:08:47 cnepveu Exp $
-----------------------------------------------------------------------------
  Copyright (c) 2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT.
-----------------------------------------------------------------------------
*/

#ifndef XML_TUN_H
#define XML_TUN_H

#ifdef XMLTUN
# define ACCESS
#else
# define ACCESS extern
#endif

typedef struct stLinkedList {
  char *Value;
  struct stLinkedList *next;
} tLinkedList;

typedef struct stTunnel {
  char *action,
       *type,
       *lifetime,
       *proxy,
       *mtu,
       *client_address_ipv4,
       *client_address_ipv6,
       *client_dns_name,
       *server_address_ipv4,
       *server_address_ipv6,
       *router_protocol,
       *prefix_length,
       *prefix,
       *client_as,
       *server_as,
       *keepalive_interval,
       *keepalive_address;
  tLinkedList *dns_server_address_ipv4,
              *dns_server_address_ipv6,
              *broker_address_ipv4,
              *broker_address_ipv6,
              *broker_redirect_ipv4,
              *broker_redirect_ipv6,
              *broker_redirect_dn;
} tTunnel;


ACCESS sint32_t     tspXMLParse           ( char *Data, tTunnel *Tunnel );
ACCESS void         tspClearTunnelInfo    ( tTunnel *Tunnel );

#undef ACCESS
#endif

