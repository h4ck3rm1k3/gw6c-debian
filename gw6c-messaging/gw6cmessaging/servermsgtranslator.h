// **************************************************************************
// $Id: servermsgtranslator.h,v 1.7 2008/01/08 19:33:57 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
//
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Defines the message processing of Gateway6 Client messages destined
//   for the Client (which is the server-side of the communication).
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cmessaging_servermsgtranslator_h__
#define __gw6cmessaging_servermsgtranslator_h__


#include <gw6cmessaging/messageprocessor.h>
#include <gw6cmessaging/gw6cuistrings.h>
#include <gw6cmessaging/hap6msgdata.h>


namespace gw6cmessaging
{
  // ------------------------------------------------------------------------
  class ServerMsgTranslator: public MessageProcessor
  {
  protected:
    // Construction / destruction.
                    ServerMsgTranslator   ( void );
  public:
    virtual         ~ServerMsgTranslator  ( void );

  protected:
    // Override from MessageProcessor.
    error_t         ProcessMessage        ( Message* pMsg );

    // To be implemented by derived classes.
    virtual error_t Recv_StatusInfoRequest( void )=0;
    virtual error_t Recv_TunnelInfoRequest( void )=0;
    virtual error_t Recv_BrokerListRequest( void )=0;
    virtual error_t Recv_HAP6ConfigInfo   ( const HAP6ConfigInfo* aHAP6ConfigInfo )=0;
    virtual error_t Recv_HAP6StatusInfoRequest( void )=0;

  private:
    // Message data translators.
    error_t         TranslateStatusInfoReq( uint8_t* pData, const uint16_t nDataLen );
    error_t         TranslateTunnelInfoReq( uint8_t* pData, const uint16_t nDataLen );
    error_t         TranslateBrokerListReq( uint8_t* pData, const uint16_t nDataLen );
    error_t         TranslateHAP6ConfigInfo( uint8_t* pData, const uint16_t nDataLen );
    error_t         TranslateHAP6StatusInfoReq( uint8_t* pData, const uint16_t nDataLen );
  };

}

#endif
