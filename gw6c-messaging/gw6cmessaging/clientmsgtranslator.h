// **************************************************************************
// $Id: clientmsgtranslator.h,v 1.6 2008/01/08 19:33:56 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
//
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Defines the message processing of Gateway6 Client messages destined
//   for the GUI (which is the client-side).
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cmessaging_clientmsgtranslator_h__
#define __gw6cmessaging_clientmsgtranslator_h__


#include <gw6cmessaging/messageprocessor.h>
#include <gw6cmessaging/gw6cuistrings.h>
#include <gw6cmessaging/gw6cmsgdata.h>
#include <gw6cmessaging/hap6msgdata.h>


namespace gw6cmessaging
{
  // ------------------------------------------------------------------------
  class ClientMsgTranslator: public MessageProcessor
  {
  protected:
    // Construction / destruction.
                    ClientMsgTranslator   ( void );
  public:
    virtual         ~ClientMsgTranslator  ( void );

  protected:
    // Override from MessageProcessor.
    error_t         ProcessMessage        ( Message* pMsg );

    // To be implemented by derived classes.
    virtual error_t Recv_StatusInfo       ( const Gw6cStatusInfo* aStatusInfo )=0;
    virtual error_t Recv_TunnelInfo       ( const Gw6cTunnelInfo* aTunnelInfo )=0;
    virtual error_t Recv_BrokerList       ( const Gw6cBrokerList* aBrokerList )=0;
    virtual error_t Recv_HAP6StatusInfo   ( const HAP6StatusInfo* aHAP6StatusInfo )=0;

  private:
    // Message data translators.
    error_t         TranslateStatusInfo   ( uint8_t* pData, const uint16_t nDataLen );
    error_t         TranslateTunnelInfo   ( uint8_t* pData, const uint16_t nDataLen );
    error_t         TranslateBrokerList   ( uint8_t* pData, const uint16_t nDataLen );
    error_t         TranslateHAP6StatusInfo( uint8_t* pData, const uint16_t nDataLen );
  };

}

#endif
