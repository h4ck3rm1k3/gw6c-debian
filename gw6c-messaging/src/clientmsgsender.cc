// **************************************************************************
// $Id: clientmsgsender.cc,v 1.7 2008/01/08 19:33:58 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
//
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Implementation of the ClientMsgSender class.
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#include <gw6cmessaging/clientmsgsender.h>
#include <assert.h>


namespace gw6cmessaging
{
// --------------------------------------------------------------------------
// Function : ClientMsgSender constructor
//
// Description:
//   Will initialize a new ClientMsgSender object.
//
// Arguments: (none)
//
// Return values: (N/A)
//
// --------------------------------------------------------------------------
ClientMsgSender::ClientMsgSender( void )
{
}

// --------------------------------------------------------------------------
// Function : ClientMsgSender destructor
//
// Description:
//   Will clean-up space allocated during object lifetime.
//
// Arguments: (none)
//
// Return values: (N/A)
//
// --------------------------------------------------------------------------
ClientMsgSender::~ClientMsgSender( void )
{
}


// --------------------------------------------------------------------------
// Function : Send_StatusRequest
//
// Description:
//   Will post a message for a status info request.
//
// Arguments: (none)
//
// Return values: (none)
//
// --------------------------------------------------------------------------
void ClientMsgSender::Send_StatusInfoRequest( void )
{
  Message* pMsg;


  // No need to send data in requests messages.
  pMsg = Message::CreateMessage( MESSAGEID_REQUEST_STATUSINFO, 0, NULL );
  assert( pMsg != NULL );


  // Post the message.
  PostMessage( pMsg );
}


// --------------------------------------------------------------------------
// Function : Send_StatusRequest
//
// Description:
//   Will post a message for a tunnel info request.
//
// Arguments: (none)
//
// Return values: (none)
//
// --------------------------------------------------------------------------
void ClientMsgSender::Send_TunnelInfoRequest( void )
{
  Message* pMsg;


  // No need to send data in requests messages.
  pMsg = Message::CreateMessage( MESSAGEID_REQUEST_TUNNELINFO, 0, NULL );
  assert( pMsg != NULL );


  // Post the message.
  PostMessage( pMsg );
}


// --------------------------------------------------------------------------
// Function : Send_StatusRequest
//
// Description:
//   Will post a message for a broker list request.
//
// Arguments: (none)
//
// Return values: (none)
//
// --------------------------------------------------------------------------
void ClientMsgSender::Send_BrokerListRequest( void )
{
  Message* pMsg;


  // No need to send data in requests messages.
  pMsg = Message::CreateMessage( MESSAGEID_REQUEST_BROKERLIST, 0, NULL );
  assert( pMsg != NULL );


  // Post the message.
  PostMessage( pMsg );
}


// --------------------------------------------------------------------------
// Function : Send_StatusRequest
//
// Description:
//   Will post a message for a broker list request.
//
// Arguments: (none)
//
// Return values: (none)
//
// --------------------------------------------------------------------------
void ClientMsgSender::Send_HAP6ConfigInfo( const HAP6ConfigInfo* aHAP6CfgInfo )
{
  Message* pMsg;
  uint8_t pData[MSG_MAX_USERDATA];
  uint32_t nDataLen = 0;

  assert( aHAP6CfgInfo != NULL );


  // ----------------------------------------------------
  // Insert HAP6 Configuration Info data in the message.
  // ----------------------------------------------------

  // Insert WWW document root.
  if( aHAP6CfgInfo->hap6_doc_root ) {
    memcpy( pData + nDataLen, aHAP6CfgInfo->hap6_doc_root, strlen(aHAP6CfgInfo->hap6_doc_root) + 1 );
    nDataLen += pal_strlen(aHAP6CfgInfo->hap6_doc_root) + 1;
  }
  else {
    memset( pData + nDataLen, 0x00, 1 );
    ++nDataLen;
  }

  // Append proxy enabled.
  memcpy( pData + nDataLen, (void*)&(aHAP6CfgInfo->hap6_proxy_enabled), sizeof(aHAP6CfgInfo->hap6_proxy_enabled) );
  nDataLen += sizeof(aHAP6CfgInfo->hap6_proxy_enabled);

  // Append web enabled.
  memcpy( pData + nDataLen, (void*)&(aHAP6CfgInfo->hap6_web_enabled), sizeof(aHAP6CfgInfo->hap6_web_enabled) );
  nDataLen += sizeof(aHAP6CfgInfo->hap6_web_enabled);

  // Append mappings changed.
  memcpy( pData + nDataLen, (void*)&(aHAP6CfgInfo->hap6_devmap_changed), sizeof(aHAP6CfgInfo->hap6_devmap_changed) );
  nDataLen += sizeof(aHAP6CfgInfo->hap6_devmap_changed);


  assert( nDataLen <= MSG_MAX_USERDATA );       // Buffer overflow has occured.


  // Create Message.
  pMsg = Message::CreateMessage( MESSAGEID_HAP6CONFIGINFO, nDataLen, pData );
  assert( pMsg != NULL );


  // Post the message.
  PostMessage( pMsg );
}


// --------------------------------------------------------------------------
// Function : Send_HAP6StatusInfoRequest
//
// Description:
//   Will post a message for a HAP6 Status Info request.
//
// Arguments: (none)
//
// Return values: (none)
//
// --------------------------------------------------------------------------
void ClientMsgSender::Send_HAP6StatusInfoRequest( void )
{
  Message* pMsg;


  // No need to send data in requests messages.
  pMsg = Message::CreateMessage( MESSAGEID_REQUEST_HAP6STATUSINFO, 0, NULL );
  assert( pMsg != NULL );


  // Post the message.
  PostMessage( pMsg );
}

} // namespace
