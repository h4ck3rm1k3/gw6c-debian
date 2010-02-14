// **************************************************************************
// $Id: gw6c_c_wrapper.cc,v 1.6 2007/02/26 19:19:44 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
// 
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Implementation of the C function wrappers.
//
// Author: Charles Nepveu
//
// Creation Date: December 2006
// __________________________________________________________________________
// **************************************************************************
#include <gw6cmessaging/gw6c_c_wrapper.h>
#include <gw6cmessaging/clientmsgdataretriever.h>
#include <gw6cmessaging/clientmessengerimpl.h>
using namespace gw6cmessaging;


// The unique instance of the GW6 Client Messenger implementation object.
static ClientMessengerImpl* pMessenger = NULL;



// --------------------------------------------------------------------------
// Function : initialize_messaging
//
// Description:
//   Will instantiate the GW6 Client Messenger Impl object, thus providing
//   Messenger capabilities to this process.
//   This implementation ensures that only one messenger object exists at a 
//   time.
//
// Arguments: (none)
//
// Return values:
//   GW6CM_UIS__NOERROR: Successful completion.
//   GW6CM_UIS_CWRAPALRDYINIT: Initialization procedure previously called.
//
// --------------------------------------------------------------------------
extern "C" error_t initialize_messaging( void )
{
  if( pMessenger != NULL )
    return GW6CM_UIS_CWRAPALRDYINIT;

  // Instantiate a new Client Messenger.
  pMessenger = new ClientMessengerImpl();

  // It is preferable to wait until the worker threads of the 
  // client messenger are ready.
  // -> Wait UP TO 750 miliseconds...
  pMessenger->WaitReady( 750 );     // Should be done within 1 or 2 ms.


  return GW6CM_UIS__NOERROR;
}


// --------------------------------------------------------------------------
// Function : uninitialize_messaging
//
// Description:
//   Will destroy the GW6 Client Messenger Impl object, thus stopping 
//   Messenger capabilities to this process.
//
// Arguments: (none)
//
// Return values:
//   GW6CM_UIS__NOERROR: Successful completion.
//   GW6CM_UIS_CWRAPNOTINIT: Messenger object had not been initialized.
//
// --------------------------------------------------------------------------
extern "C" error_t uninitialize_messaging( void )
{
  if( pMessenger == NULL )
    return GW6CM_UIS_CWRAPNOTINIT;

  delete pMessenger;
  pMessenger = NULL;

  return GW6CM_UIS__NOERROR;
}


// --------------------------------------------------------------------------
// Function : send_status_info
//
// Description:
//   Sends status info to the GUI (or whichever client that's connected).
//
// Arguments: (none)
//
// Return values:
//   GW6CM_UIS__NOERROR: Successful completion.
//   GW6CM_UIS_CWRAPNOTINIT: Messenger not initialized.
//
// --------------------------------------------------------------------------
extern "C" error_t send_status_info( void )
{
  Gw6cStatusInfo* pStatusInfo = NULL;
  error_t retCode = GW6CM_UIS__NOERROR;


  // Verify if messenger object has been initialized.
  if( pMessenger == NULL )
    return GW6CM_UIS_CWRAPNOTINIT;

  // Callback to the GW6 Client process, to gather required information.
  retCode = RetrieveStatusInfo( &pStatusInfo );
  if( retCode == GW6CM_UIS__NOERROR )
  {
    // Send the tunnel info to the other side.
    pMessenger->Send_StatusInfo( pStatusInfo );

    // Frees the memory used by the StatusInfo object.
    FreeStatusInfo( &pStatusInfo );
  }

  return retCode;
}


// --------------------------------------------------------------------------
// Function : send_tunnel_info
//
// Description:
//   Sends tunnel info to the GUI (or whichever client that's connected).
//
// Arguments: (none)
//
// Return values:
//   GW6CM_UIS__NOERROR: Successful completion.
//   GW6CM_UIS_CWRAPNOTINIT: Messenger not initialized.
//
// --------------------------------------------------------------------------
extern "C" error_t send_tunnel_info( void )
{
  Gw6cTunnelInfo* pTunnelInfo = NULL;
  error_t retCode = GW6CM_UIS__NOERROR;


  // Verify if messenger object has been initialized.
  if( pMessenger == NULL )
    return GW6CM_UIS_CWRAPNOTINIT;

  // Callback to the GW6 Client process, to gather required information.
  retCode = RetrieveTunnelInfo( &pTunnelInfo );
  if( retCode == GW6CM_UIS__NOERROR )
  {
    // Send the tunnel info to the other side.
    pMessenger->Send_TunnelInfo( pTunnelInfo );

    // Frees the memory used by the TunnelInfo object.
    FreeTunnelInfo( &pTunnelInfo );
  }

  return retCode;
}


// --------------------------------------------------------------------------
// Function : send_broker_list
//
// Description:
//   Sends broker list to the GUI (or whichever client that's connected).
//
// Arguments: (none)
//
// Return values:
//   GW6CM_UIS__NOERROR: Successful completion.
//   GW6CM_UIS_CWRAPNOTINIT: Messenger not initialized.
//
// --------------------------------------------------------------------------
extern "C" error_t send_broker_list( void )
{
  Gw6cBrokerList* pBrokerList = NULL;
  error_t retCode = GW6CM_UIS__NOERROR;


  // Verify if messenger object has been initialized.
  if( pMessenger == NULL )
    return GW6CM_UIS_CWRAPNOTINIT;

  // Callback to the GW6 Client process, to gather required information.
  retCode = RetrieveBrokerList( &pBrokerList );
  if( retCode == GW6CM_UIS__NOERROR )
  {
    // Send the broker list to the other side.
    pMessenger->Send_BrokerList( pBrokerList );

    // Frees the memory used by the BrokerList object.
    FreeBrokerList( &pBrokerList );
  }

  return retCode;
}


// --------------------------------------------------------------------------
// Function : send_hap6_status_info
//
// Description:
//   Sends HAP6 status info to the GUI (or whichever client that's connected).
//
// Arguments: (none)
//
// Return values:
//   GW6CM_UIS__NOERROR: Successful completion.
//   GW6CM_UIS_CWRAPNOTINIT: Messenger not initialized.
//
// --------------------------------------------------------------------------
extern "C" error_t send_hap6_status_info( void )
{
  HAP6StatusInfo* pHAP6StatusInfo = NULL;
  error_t retCode = GW6CM_UIS__NOERROR;


  // Verify if messenger object has been initialized.
  if( pMessenger == NULL )
    return GW6CM_UIS_CWRAPNOTINIT;

  // Callback to the GW6 Client process, to gather required information.
  retCode = RetrieveHAP6StatusInfo( &pHAP6StatusInfo );
  if( retCode == GW6CM_UIS__NOERROR )
  {
    // Send the HAP6 status info to the other side.
    pMessenger->Send_HAP6StatusInfo( pHAP6StatusInfo );

    // Frees the memory used by the HAP6StatusInfo object.
    FreeHAP6StatusInfo( &pHAP6StatusInfo );
  }

  return retCode;
}



