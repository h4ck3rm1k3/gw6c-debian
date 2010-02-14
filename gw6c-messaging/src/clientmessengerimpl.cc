// **************************************************************************
// $Id: clientmessengerimpl.cc,v 1.11 2008/01/08 19:33:58 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
// 
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Implementation of the ClientMessengerImpl class.
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#include <gw6cmessaging/clientmessengerimpl.h>
#include <gw6cmessaging/clientmsgdataretriever.h>
#include <gw6cmessaging/clientmsgnotifier.h>


namespace gw6cmessaging
{
// --------------------------------------------------------------------------
// Function : ClientMessengerImpl constructor
//
// Description:
//   Will initialize a new ClientMessengerImpl object.
//
// Arguments: (none)
//
// Return values: (N/A)
//
// --------------------------------------------------------------------------
ClientMessengerImpl::ClientMessengerImpl( void ) :
  ServerMsgSender(), 
  ServerMsgTranslator(),
  m_CommManager( SERVER_MANAGER, this )
{
  m_CommManager.Run();
}


// --------------------------------------------------------------------------
// Function : ClientMessengerImpl destructor
//
// Description:
//   Will clean-up space allocated during object lifetime.
//
// Arguments: (none)
//
// Return values: (N/A)
//
// --------------------------------------------------------------------------
ClientMessengerImpl::~ClientMessengerImpl( void )
{
}


// --------------------------------------------------------------------------
// Function : Recv_StatusInfoRequest
//
// Description:
//   Will wait on the communication manager to get ready. If ready state is 
//   not signalled within XXX miliseconds, this function exits.
//
// Arguments:
//   ulWaitms: unsigned long [IN], the time to wait for ready state.
//
// Return values:
//   true: communications manager signalled ready state within XX miliseconds
///  false: ready state was not signalled within the XX miliseconds.
//
// --------------------------------------------------------------------------
bool ClientMessengerImpl::WaitReady( unsigned long ulWaitms )
{
  return m_CommManager.WaitReady( ulWaitms );
}


// --------------------------------------------------------------------------
// Function : Recv_StatusInfoRequest
//
// Description:
//   Will gather information on the Gateway6 Client status and send it to the
//   requester.
//
// Arguments: (none)
//
// Return values:
//   GW6CM_UIS__NOERROR: Indicates success replying to request.
//
// --------------------------------------------------------------------------
error_t ClientMessengerImpl::Recv_StatusInfoRequest( void )
{
  Gw6cStatusInfo* pStatusInfo = NULL;
  error_t retCode;


  // Retrieve the status information. (ALLOCATION MADE HERE)
  retCode = RetrieveStatusInfo( &pStatusInfo );
  if( retCode == GW6CM_UIS__NOERROR )
  {
    // Send the information to the requester.
    Send_StatusInfo( pStatusInfo );

    // Free memory allocated.
    FreeStatusInfo( &pStatusInfo );
  }

  return retCode;
}


// --------------------------------------------------------------------------
// Function : Recv_TunnelInfoRequest
//
// Description:
//   Will gather information on the tunnel and send it to the requester.
//
// Arguments: (none)
//
// Return values:
//   GW6CM_UIS__NOERROR: Indicates success replying to request.
//
// --------------------------------------------------------------------------
error_t ClientMessengerImpl::Recv_TunnelInfoRequest( void )
{
  Gw6cTunnelInfo* pTunnelInfo = NULL;
  error_t retCode;


  // Retrieve the status information. (ALLOCATION MADE HERE)
  retCode = RetrieveTunnelInfo( &pTunnelInfo );
  if( retCode == GW6CM_UIS__NOERROR )
  {
    // Send the information to the requester.
    Send_TunnelInfo( pTunnelInfo );

    // Free memory allocated.
    FreeTunnelInfo( &pTunnelInfo );
  }

  return retCode;
}


// --------------------------------------------------------------------------
// Function : Recv_BrokerListRequest
//
// Description:
//   Will gather the information on the list of brokers, and put it in a list
//   and sent it to the requester.
//
// Arguments: (none)
//
// Return values:
//   GW6CM_UIS__NOERROR: Indicates success receiving request.
//
// --------------------------------------------------------------------------
error_t ClientMessengerImpl::Recv_BrokerListRequest( void )
{
  Gw6cBrokerList* pBrokerList = NULL;
  error_t retCode;


  // Retrieve the broker list. (ALLOCATION MADE HERE)
  retCode = RetrieveBrokerList( &pBrokerList );
  if( retCode == GW6CM_UIS__NOERROR )
  {
    // Send the information to the requester.
    Send_BrokerList( pBrokerList );

    // Free memory allocated.
    FreeBrokerList( &pBrokerList );
  }

  return retCode;
}


// --------------------------------------------------------------------------
// Function : Recv_HAP6ConfigInfo
//
// Description:
//   Will call the C function that is implemented in the GW6C.
//
// Arguments: (none)
//
// Return values:
//   GW6CM_UIS__NOERROR: Indicates success receiving message.
//
// --------------------------------------------------------------------------
error_t ClientMessengerImpl::Recv_HAP6ConfigInfo( const HAP6ConfigInfo* aHAP6ConfigInfo )
{
  // C++ -> C bridge

  // This C function is implemented in the Gateway6 Client.
  return NotifyHap6ConfigInfo( aHAP6ConfigInfo );
}


// --------------------------------------------------------------------------
// Function : Recv_HAP6StatusInfoRequest
//
// Description:
//   Will gather information on the HAP6 Status and send it to the requester.
//
// Arguments: (none)
//
// Return values:
//   GW6CM_UIS__NOERROR: Indicates success replying to request.
//
// --------------------------------------------------------------------------
error_t ClientMessengerImpl::Recv_HAP6StatusInfoRequest( void )
{
  HAP6StatusInfo* pHAP6StatusInfo = NULL;
  error_t retCode;


  // Retrieve the status information. (ALLOCATION MADE HERE)
  retCode = RetrieveHAP6StatusInfo( &pHAP6StatusInfo );
  if( retCode == GW6CM_UIS__NOERROR )
  {
    // Send the information to the requester.
    Send_HAP6StatusInfo( pHAP6StatusInfo );

    // Free memory allocated.
    FreeHAP6StatusInfo( &pHAP6StatusInfo );
  }

  return retCode;
}


// --------------------------------------------------------------------------
// Function : PostMessage
//
// Description:
//   Will post a message to the send queue for sending.
//
// Arguments:
//   pMsg: Message* [IN], The message to post.
//
// Return values: (none)
//
// --------------------------------------------------------------------------
void ClientMessengerImpl::PostMessage( Message* pMsg )
{
  MessageSender* pSender = (MessageSender*) &m_CommManager;
  pSender->PostMessage( pMsg );
}

} // namespace
