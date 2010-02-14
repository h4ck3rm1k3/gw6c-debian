// **************************************************************************
// $Id: gw6c_c_wrapper.h,v 1.4 2007/02/26 19:19:42 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
// 
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Provides C access to the gateway6 client messenger subsystem.
//   The C functionnality here is limited to the Gateway6 Client (not the 
//   GUI).
//
// Author: Charles Nepveu
//
// Creation Date: December 2006
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cmessaging_gw6c_c_wrapper_h__
#define __gw6cmessaging_gw6c_c_wrapper_h__


#include <gw6cmessaging/gw6cuistrings.h>      // error_t definition & codes.
#include <gw6cmessaging/gw6cmsgdata.h>        // messaging data.
#include <gw6cmessaging/hap6msgdata.h>        // HAP6 messaging data.


#ifdef __cplusplus
extern "C" {
#endif

// Initialization of the underlying C++ object.
error_t             initialize_messaging  ( void );
error_t             uninitialize_messaging( void );

// Send functions. They don't take arguments because they'll be using
// the clientmsgdataretriever functions (See clientmsgdataretriever.h).
error_t             send_status_info      ( void );
error_t             send_tunnel_info      ( void );
error_t             send_broker_list      ( void );
error_t             send_hap6_status_info ( void );


// Will be declared in: tsp_client.c
extern Gw6cStatusInfo gStatusInfo;
extern Gw6cTunnelInfo gTunnelInfo;
extern HAP6StatusInfo gHAP6StatusInfo;


#ifdef __cplusplus
}
#endif

#endif
