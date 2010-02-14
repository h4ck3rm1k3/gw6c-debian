// **************************************************************************
// $Id: clientmessengerimpl.h,v 1.6 2007/04/02 20:12:02 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
// 
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   This is the Gateway6 Client implementation of the messenger subsystem.
//   The naming of the derived class as `server' indicate that the Gateway6
//   Client only means that it is the server-side of the messaging subsystem.
//   (The GUI is the client-side of the messaging subsystem.)
//
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cmessaging_clientmessengerimpl_h__
#define __gw6cmessaging_clientmessengerimpl_h__


#include <gw6cmessaging/servermsgsender.h>
#include <gw6cmessaging/servermsgtranslator.h>
#include <gw6cmessaging/communicationsmgr.h>
#undef PostMessage


namespace gw6cmessaging
{

  // ------------------------------------------------------------------------
  class ClientMessengerImpl : public ServerMsgSender, public ServerMsgTranslator
  {
  private:
    CommunicationsManager m_CommManager;

  public:
                    ClientMessengerImpl   ( void );
    virtual         ~ClientMessengerImpl  ( void );

    // Waits until communication manager is ready.
    bool            WaitReady             ( unsigned long ulWaitms=750 );

    // Overrides from the ServerMsgTranslator:
    error_t         Recv_StatusInfoRequest( void );
    error_t         Recv_TunnelInfoRequest( void );
    error_t         Recv_BrokerListRequest( void );
    error_t         Recv_HAP6ConfigInfo   ( const HAP6ConfigInfo* aHAP6ConfigInfo );
    error_t         Recv_HAP6StatusInfoRequest( void );

    // Overrides from the ServerMsgSender:
    void            PostMessage           ( Message* pMsg );
  };

}

#endif
