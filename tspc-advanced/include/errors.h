/*
-----------------------------------------------------------------------------
 $Id: errors.h,v 1.21 2008/01/09 15:08:46 cnepveu Exp $
-----------------------------------------------------------------------------
  Copyright (c) 2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT.
-----------------------------------------------------------------------------
*/

#ifndef _ERRORS_H_
#define _ERRORS_H_

/* globals */

#ifdef NO_ERROR
#undef NO_ERROR
#endif

#ifdef TSP_ERROR
#undef TSP_ERROR
#endif

#ifdef SOCKET_ERROR
#undef SOCKET_ERROR
#endif

#ifdef INTERFACE_SETUP_FAILED
#undef INTERFACE_SETUP_FAILED
#endif

#ifdef KEEPALIVE_TIMEOUT
#undef KEEPALIVE_TIMEOUT
#endif

#ifdef TUNNEL_ERROR
#undef TUNNEL_ERROR
#endif

typedef enum {
  NO_ERROR = 0,
  NO_ERROR_SHOW_HELP,
  TSP_ERROR,
  SOCKET_ERROR,
  INTERFACE_SETUP_FAILED,
  KEEPALIVE_TIMEOUT,
  KEEPALIVE_ERROR,
  TUNNEL_ERROR,
  TSP_VERSION_ERROR,
  AUTHENTICATION_ERROR,
  LEASE_EXPIRED,
  SERVER_SIDE_ERROR,
  INVALID_ARGUMENTS,
  MEMORY_ERROR,
  INVALID_SERVER,
  INVALID_CONFIG_FILE,
  INVALID_CLIENT_IPV4,
  INVALID_CLIENT_IPV6,
  LOGGING_CONFIGURATION_ERROR,
  BROKER_REDIRECTION,
  BROKER_REDIRECTION_ERROR,
  SOCKET_ERROR_CANT_CONNECT,
  INITIALIZATION_ERROR,
#ifdef HAP6
  HAP6_INITIALIZATION_ERROR,
  HAP6_SETUP_ERROR,
  HAP6_EXPOSE_DEVICES_ERROR
#endif
} tErrors;

#endif
