// **************************************************************************
// $Id: guimessengerimpl.cc,v 1.5 2007/02/23 21:30:26 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
// 
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Implementation of the GUIMessengerImpl class.
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#include <gw6cmessaging/guimessengerimpl.h>
#include <gw6cmessaging/gw6cmsgdata.h>


namespace gw6cmessaging
{
// --------------------------------------------------------------------------
// Function : GUIMessengerImpl constructor
//
// Description:
//   Will initialize a new GUIMessengerImpl object.
//
// Arguments: (none)
//
// Return values: (N/A)
//
// --------------------------------------------------------------------------
GUIMessengerImpl::GUIMessengerImpl( void ) :
  ClientMsgSender(), 
  ClientMsgTranslator(),
  m_RecvStatusInfo(NULL),
  m_RecvTunnelInfo(NULL),
  m_RecvBrokerList(NULL),
  m_RecvHAP6StatusInfo(NULL),
  m_CommManager( CLIENT_MANAGER, this )
{
  // Message processing is enabled by default in ClientMsgTranslator.
  m_CommManager.Run();
}


// --------------------------------------------------------------------------
// Function : GUIMessengerImpl destructor
//
// Description:
//   Will clean-up space allocated during object lifetime.
//
// Arguments: (none)
//
// Return values: (N/A)
//
// --------------------------------------------------------------------------
GUIMessengerImpl::~GUIMessengerImpl( void )
{
}


// --------------------------------------------------------------------------
// Function : DisableProcessing
//
// Description:
//   Will disable message processing. Incoming messages will be dropped.
//   Useful when you want callbacks to stop being invoked.
//   NOTE: This does not disable message sending.
//
// Arguments: (none)
//
// Return values: (none)
//
// --------------------------------------------------------------------------
void GUIMessengerImpl::DisableProcessing( void )
{
  MessageProcessor::m_eProcessorState = STATE_DISABLED;
}


// --------------------------------------------------------------------------
// Function : EnableProcessing
//
// Description:
//   Will enable(resume) message processing.
//
// Arguments: (none)
//
// Return values: (none)
//
// --------------------------------------------------------------------------
void GUIMessengerImpl::EnableProcessing( void )
{
  MessageProcessor::m_eProcessorState = STATE_ENABLED;
}


// --------------------------------------------------------------------------
// Function : Recv_StatusInfo
//
// Description:
//   Invoked upon reception of a StatusInfo message from the Communications
//   Manager. The information contains the GW6Client status.
//
// Arguments:
//   aStatusInfo: Gw6cStatusInfo* [IN], The client status.
//
// Return values:
//   GW6CM_UIS__NOERROR: Indicates success replying to request.
//
// --------------------------------------------------------------------------
error_t GUIMessengerImpl::Recv_StatusInfo( const Gw6cStatusInfo* aStatusInfo )
{
  // Callback the provided function.
  if( m_RecvStatusInfo != NULL )
    (*m_RecvStatusInfo)( aStatusInfo );

  return GW6CM_UIS__NOERROR;
}


// --------------------------------------------------------------------------
// Function : Recv_TunnelInfo
//
// Description:
//   Invoked upon reception of a TunnelInfo message from the Communications
//   Manager. The information contains the GW6Client tunnel info.
//
// Arguments:
//   aTunnelInfo: Gw6cTunnelInfo* [IN], The tunnel information.
//
// Return values:
//   GW6CM_UIS__NOERROR: Indicates success replying to request.
//
// --------------------------------------------------------------------------
error_t GUIMessengerImpl::Recv_TunnelInfo( const Gw6cTunnelInfo* aTunnelInfo )
{
  // Callback the provided function.
  if( m_RecvTunnelInfo != NULL )
    (*m_RecvTunnelInfo)(aTunnelInfo);

  return GW6CM_UIS__NOERROR;
}


// --------------------------------------------------------------------------
// Function : Recv_BrokerList
//
// Description:
//   Invoked upon reception of a BrokerList message from the Communications
//   Manager. The information contains the GW6Client list of brokers.
//
// Arguments:
//   aBrokerList: Gw6cBrokerList* [IN], The list of brokers.
//
// Return values:
//   GW6CM_UIS__NOERROR: Indicates success replying to request.
//
// --------------------------------------------------------------------------
error_t GUIMessengerImpl::Recv_BrokerList( const Gw6cBrokerList* aBrokerList )
{
  // Callback the provided function.
  if( m_RecvBrokerList != NULL )
    (*m_RecvBrokerList)(aBrokerList);

  return GW6CM_UIS__NOERROR;
}


// --------------------------------------------------------------------------
// Function : Recv_HAP6StatusInfo
//
// Description:
//   Invoked upon reception of a BrokerList message from the Communications
//   Manager. The information contains the statuses of the HAP6 features.
//
// Arguments:
//   aBrokerList: aHAP6StatusInfo* [IN], The HAP6 status information.
//
// Return values:
//   GW6CM_UIS__NOERROR: Indicates success replying to request.
//
// --------------------------------------------------------------------------
error_t GUIMessengerImpl::Recv_HAP6StatusInfo( const HAP6StatusInfo* aHAP6StatusInfo )
{
  // Callback the provided function.
  if( m_RecvHAP6StatusInfo != NULL )
    (*m_RecvHAP6StatusInfo)(aHAP6StatusInfo);

  return GW6CM_UIS__NOERROR;
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
void GUIMessengerImpl::PostMessage( Message* pMsg )
{
  MessageSender* pSender = (MessageSender*) &m_CommManager;
  pSender->PostMessage( pMsg );
}

} // namespace
