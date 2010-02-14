// **************************************************************************
// $Id: servermsgsender.cc,v 1.15 2008/01/08 19:33:59 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
//
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Implementation of the ServerMsgSender class.
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#include <gw6cmessaging/servermsgsender.h>
#include <assert.h>


namespace gw6cmessaging
{
// --------------------------------------------------------------------------
// Function : ServerMsgSender constructor
//
// Description:
//   Will initialize a new ServerMsgSender object.
//
// Arguments: (none)
//
// Return values: (N/A)
//
// --------------------------------------------------------------------------
ServerMsgSender::ServerMsgSender( void )
{
}

// --------------------------------------------------------------------------
// Function : ServerMsgSender destructor
//
// Description:
//   Will clean-up space allocated during object lifetime.
//
// Arguments: (none)
//
// Return values: (N/A)
//
// --------------------------------------------------------------------------
ServerMsgSender::~ServerMsgSender( void )
{
}


// --------------------------------------------------------------------------
// Function : Send_StatusInfo
//
// Description:
//   Will send information on the status of the Gateway6 Client.
//   A message is created with the information and posted to the send queue.
//
// Arguments:
//   aStatusInfo: Gw6cStatusInfo* [in], The current state of the gateway6
//                client.
//
// Return values: (none)
//
// --------------------------------------------------------------------------
void ServerMsgSender::Send_StatusInfo( const Gw6cStatusInfo* aStatusInfo )
{
  Message* pMsg;
  uint8_t pData[MSG_MAX_USERDATA];
  unsigned int nDataLen = 0;


  assert( aStatusInfo != NULL );


  // Write client status to data buffer.
  memcpy( pData, (void*)&(aStatusInfo->eStatus), sizeof(Gw6cCliStatus) );
  nDataLen += sizeof(Gw6cCliStatus);

  // Append status code to nStatus.
  memcpy( pData + nDataLen, (void*)&(aStatusInfo->nStatus), sizeof(aStatusInfo->nStatus) );
  nDataLen += sizeof(aStatusInfo->nStatus);


  assert( nDataLen <= MSG_MAX_USERDATA );       // Buffer overflow has occured.


  // Create Message
  pMsg = Message::CreateMessage( MESSAGEID_STATUSINFO, nDataLen, pData );
  assert( pMsg != NULL );


  // Post the message.
  PostMessage( pMsg );
}


// --------------------------------------------------------------------------
// Function : Send_TunnelInfo
//
// Description:
//   Will send information on the established tunnel of the Gateway6 Client.
//   A message is created with the information and posted to the send queue.
//
// Arguments: (none)
//
// Return values: (none)
//
// --------------------------------------------------------------------------
void ServerMsgSender::Send_TunnelInfo( const Gw6cTunnelInfo* aTunnelInfo )
{
  Message* pMsg;
  uint8_t pData[MSG_MAX_USERDATA];
  uint16_t nDataLen = 0;


  assert( aTunnelInfo != NULL );


  // Append broker name to data buffer.
  if( aTunnelInfo->szBrokerName ) {
    memcpy( pData + nDataLen, aTunnelInfo->szBrokerName, strlen(aTunnelInfo->szBrokerName) + 1 );
    nDataLen += (uint16_t)strlen(aTunnelInfo->szBrokerName) + 1;
  }
  else {
    memset( pData + nDataLen, 0x00, 1 );
    ++nDataLen;
  }

  // Append tunnel type to data buffer.
  memcpy( pData + nDataLen, (void*)&(aTunnelInfo->eTunnelType), sizeof(Gw6cTunnelType) );
  nDataLen += sizeof(Gw6cTunnelType);

  // Append Local tunnel endpoint IPv4 address to data buffer.
  if( aTunnelInfo->szIPV4AddrLocalEndpoint ) {
    memcpy( pData + nDataLen, aTunnelInfo->szIPV4AddrLocalEndpoint, strlen(aTunnelInfo->szIPV4AddrLocalEndpoint) + 1 );
    nDataLen += (uint16_t)strlen(aTunnelInfo->szIPV4AddrLocalEndpoint) + 1;
  }
  else {
    memset( pData + nDataLen, 0x00, 1 );
    ++nDataLen;
  }

  // Append Local tunnel endpoint IPv6 address to data buffer.
  if( aTunnelInfo->szIPV6AddrLocalEndpoint ) {
    memcpy( pData + nDataLen, aTunnelInfo->szIPV6AddrLocalEndpoint, strlen(aTunnelInfo->szIPV6AddrLocalEndpoint) + 1 );
    nDataLen += (uint16_t)strlen(aTunnelInfo->szIPV6AddrLocalEndpoint) + 1;
  }
  else {
    memset( pData + nDataLen, 0x00, 1 );
    ++nDataLen;
  }

  // Append Remote tunnel endpoint IPv4 address to data buffer.
  if( aTunnelInfo->szIPV4AddrRemoteEndpoint ) {
    memcpy( pData + nDataLen, aTunnelInfo->szIPV4AddrRemoteEndpoint, strlen(aTunnelInfo->szIPV4AddrRemoteEndpoint) + 1 );
    nDataLen += (uint16_t)strlen(aTunnelInfo->szIPV4AddrRemoteEndpoint) + 1;
  }
  else {
    memset( pData + nDataLen, 0x00, 1 );
    ++nDataLen;
  }

  // Append Remote tunnel endpoint IPv6 address to data buffer.
  if( aTunnelInfo->szIPV6AddrRemoteEndpoint ) {
    memcpy( pData + nDataLen, aTunnelInfo->szIPV6AddrRemoteEndpoint, strlen(aTunnelInfo->szIPV6AddrRemoteEndpoint) + 1 );
    nDataLen += (uint16_t)strlen(aTunnelInfo->szIPV6AddrRemoteEndpoint) + 1;
  }
  else {
    memset( pData + nDataLen, 0x00, 1 );
    ++nDataLen;
  }

  // Append The delegated prefix to data buffer.
  if( aTunnelInfo->szDelegatedPrefix ) {
    memcpy( pData + nDataLen, aTunnelInfo->szDelegatedPrefix, strlen(aTunnelInfo->szDelegatedPrefix) + 1 );
    nDataLen += (uint16_t)strlen(aTunnelInfo->szDelegatedPrefix) + 1;
  }
  else {
    memset( pData + nDataLen, 0x00, 1 );
    ++nDataLen;
  }

  // Append The delegated user domain to data buffer.
  if( aTunnelInfo->szUserDomain ) {
    memcpy( pData + nDataLen, aTunnelInfo->szUserDomain, strlen(aTunnelInfo->szUserDomain) + 1 );
    nDataLen += (uint16_t)strlen(aTunnelInfo->szUserDomain) + 1;
  }
  else {
    memset( pData + nDataLen, 0x00, 1 );
    ++nDataLen;
  }

  // Append tunnel uptime to data buffer.
  memcpy( pData + nDataLen, (void*)&(aTunnelInfo->tunnelUpTime), sizeof(time_t) );
  nDataLen += sizeof(time_t);

  assert( nDataLen <= MSG_MAX_USERDATA );       // Buffer overflow has occured.


  // Create Message.
  pMsg = Message::CreateMessage( MESSAGEID_TUNNELINFO, nDataLen, pData );
  assert( pMsg != NULL );


  // Post the message.
  PostMessage( pMsg );
}


// --------------------------------------------------------------------------
// Function : Send_BrokerList
//
// Description:
//   Will send a list of brokers.
//   A message is created with the information and posted to the send queue.
//
// Arguments:
//   aBrokerList: Gw6cBrokerList* [IN], The list of broker names.
//
// Return values: (none)
//
// --------------------------------------------------------------------------
void ServerMsgSender::Send_BrokerList( const Gw6cBrokerList* aBrokerList )
{
  Message* pMsg;
  uint8_t pData[MSG_MAX_USERDATA];
  Gw6cBrokerList* list = (Gw6cBrokerList*)aBrokerList;
  unsigned int nDataLen = 0;


  assert( aBrokerList != NULL );


  // Loop until the list is empty.
  do
  {
    // Append broker name to data buffer.
    if( list->szAddress ) {
      memcpy( pData + nDataLen, list->szAddress, strlen(list->szAddress) + 1 );
      nDataLen += (uint16_t)strlen(list->szAddress) + 1;
    }
    else {
      memset( pData + nDataLen, 0x00, 1 );
      ++nDataLen;
    }

    // Append distance
    memcpy( pData + nDataLen, (void*)&(list->nDistance), sizeof(int) );
    nDataLen += sizeof(int);


    assert( nDataLen <= MSG_MAX_USERDATA );     // Buffer overflow occured.

  } while( (list = list->next) != NULL );


  // Create Message.
  pMsg = Message::CreateMessage( MESSAGEID_BROKERLIST, nDataLen, pData );
  assert( pMsg != NULL );


  // Post the message.
  PostMessage( pMsg );
}



// --------------------------------------------------------------------------
// Function : Send_HAP6StatusInfo
//
// Description:
//   Will send the HAP6 Status Info.
//   A message is created with the information and posted to the send queue.
//
// Arguments:
//   aHAP6StatusInfo: HAP6StatusInfo* [IN], The HAP6 Status info.
//
// Return values: (none)
//
// --------------------------------------------------------------------------
void ServerMsgSender::Send_HAP6StatusInfo( const HAP6StatusInfo* aHAP6StatusInfo )
{
  Message* pMsg;
  uint8_t pData[MSG_MAX_USERDATA];
  PMAPPING_STATUS list = aHAP6StatusInfo->hap6_devmap_statuses;
  unsigned int nDataLen = 0;


  assert( aHAP6StatusInfo != NULL );


  // Insert HAP6 features statuses (web, proxy, DMM).
  // Append HAP6 proxying status
  memcpy( pData + nDataLen, (void*)&(aHAP6StatusInfo->hap6_proxy_status), sizeof(HAP6FeatStts) );
  nDataLen += sizeof(HAP6FeatStts);

  // Append HAP6 web service status
  memcpy( pData + nDataLen, (void*)&(aHAP6StatusInfo->hap6_web_status), sizeof(HAP6FeatStts) );
  nDataLen += sizeof(HAP6FeatStts);

  // Append Device Mapping Module status
  memcpy( pData + nDataLen, (void*)&(aHAP6StatusInfo->hap6_devmapmod_status), sizeof(HAP6FeatStts) );
  nDataLen += sizeof(HAP6FeatStts);


  // Append the device mapping statuses.
  if( list != NULL )
  {
    do
    {
      // Append device name to data buffer.
      if( list->device_name ) {
        memcpy( pData + nDataLen, list->device_name, strlen(list->device_name) + 1 );
        nDataLen += (uint16_t)strlen(list->device_name) + 1;
      }
      else {
        memset( pData + nDataLen, 0x00, 1 );
        ++nDataLen;
      }

      // Append mapping status
      memcpy( pData + nDataLen, (void*)&(list->mapping_status), sizeof(HAP6DevMapStts) );
      nDataLen += sizeof(HAP6DevMapStts);

      assert( nDataLen <= MSG_MAX_USERDATA );     // Buffer overflow occured.

    } while( (list = list->next) != NULL );
  }


  // Create Message.
  pMsg = Message::CreateMessage( MESSAGEID_HAP6STATUSINFO, nDataLen, pData );
  assert( pMsg != NULL );


  // Post the message.
  PostMessage( pMsg );
}

} // namespace
