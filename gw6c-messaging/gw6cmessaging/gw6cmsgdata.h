// **************************************************************************
// $Id: gw6cmsgdata.h,v 1.10 2007/04/05 22:35:23 krause Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
//
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   This include file describes the domain values and data that will be
//   exchanged between the Gateway6 Client GUI and Gateway6 Client.
//
//   These structures must be defined in C-style for integration
//   in the Gateway6 Client.
//
//   You may extend the structures to include new data, - BUT -
//   Remember to do the following:
//   - Translate the new data.
//   - Encode then new data.
//   - *THINK* of backwards compatibility (Maybe crate a new message ID
//      for the extended structure and preserve functionnality).
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cmessaging_gw6cmsgdata_h__
#define __gw6cmessaging_gw6cmsgdata_h__


#include <time.h>


// Gateway6 Client status information: Gw6cCliStatus - (Enumeration)
//   - DISCONNECTEDIDLE: Client is disconnected (idle: No connection attempt)
//   - DISCONNECTEDERROR: Client is disconnected because of an error.
//   - DISCONNECTEDNORETRY: Client was connected and will NOT retry.
//   - DISCONNECTEDHAP6SETUPERROR: Client was disconnected because of an HAP6 setup error.
//   - DISCONNECTEDHAP6EXPOSEDEVICESERROR: Client was disconnected because of an HAP6 device mapping error.
//   - CONNECTING: Client is negotiating tunnel and setting up.
//   - CONNECTED: Client is successfully connected.
//
typedef enum { GW6C_CLISTAT__DISCONNECTEDIDLE,
               GW6C_CLISTAT__DISCONNECTEDNORETRY,
               GW6C_CLISTAT__DISCONNECTEDERROR,
               GW6C_CLISTAT__DISCONNECTEDHAP6SETUPERROR,
               GW6C_CLISTAT__DISCONNECTEDHAP6EXPOSEDEVICESERROR,
               GW6C_CLISTAT__CONNECTING,
               GW6C_CLISTAT__CONNECTED } Gw6cCliStatus;


// Gateway6 Client tunnel types: Gw6cTunnelType - (Enumeration)
//   (See application manual if you don't understand these values).
typedef enum { TUNTYPE_V6V4,
               TUNTYPE_V6UDPV4,
               TUNTYPE_V4V6 } Gw6cTunnelType;


// Gateway6 Client status information: Gw6cStatusInfo - (Data structure)
//   - eStatus: The status, as described earlier.
//   - szStatus: Additionnal information on the status (error, mostly).
//
typedef struct __STATUS_INFO
{
  Gw6cCliStatus eStatus;
  signed int    nStatus;
} Gw6cStatusInfo;


// Gateway6 Client tunnel information: Gw6cTunnelInfo - (Data structure)
//   - szBrokerName: The name of the broker used for tunnel negotiation.
//   - eTunnelType: Type of tunnel.
//   - szIPV4AddrLocalEndpoint: Local tunnel endpoint IPv4 address.
//   - szIPV6AddrLocalEndpoint: Local tunnel endpoint IPv6 address.
//   - szIPV4AddrRemoteEndpoint: Remote tunnel endpoint IPv4 address.
//   - szIPV6AddrRemoteEndpoint: Remote tunnel endpoint IPv6 address.
//   - szDelegatedPrefix: The delegated prefix (if routing is enabled).
//   - szUserDomain: The domain delegated to the used for his prefix.
//   - tunnelUpTime: c-time at which the tunnel was 'up'. NOT THE UPTIME.
//
typedef struct __TUNNEL_INFO
{
  char* szBrokerName;
  Gw6cTunnelType eTunnelType;
  char* szIPV4AddrLocalEndpoint;
  char* szIPV6AddrLocalEndpoint;
  char* szIPV4AddrRemoteEndpoint;
  char* szIPV6AddrRemoteEndpoint;
  char* szDelegatedPrefix;
  char* szUserDomain;
  time_t tunnelUpTime;
} Gw6cTunnelInfo;


// Gateway6 Client broker list: Gw6cBrokerList - (Data structure)
//   - szBrokerName: Name of the broker.
//   - next: Next element in the list: NULL if end.
//
struct __BROKER_LIST;
typedef struct __BROKER_LIST
{
  char* szAddress;
  int   nDistance;
  struct __BROKER_LIST* next;
} Gw6cBrokerList;


#endif
