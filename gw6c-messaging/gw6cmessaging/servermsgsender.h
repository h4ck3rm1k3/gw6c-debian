// **************************************************************************
// $Id: servermsgsender.h,v 1.6 2007/02/23 21:30:25 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
// 
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Defines the different messages the Gateway6 Client can send.
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cmessaging_servermsgsender_h__
#define __gw6cmessaging_servermsgsender_h__


#include <gw6cmessaging/messagesender.h>
#include <gw6cmessaging/gw6cuistrings.h>
#include <gw6cmessaging/gw6cmsgdata.h>
#include <gw6cmessaging/hap6msgdata.h>
#undef PostMessage


namespace gw6cmessaging
{
  // ------------------------------------------------------------------------
  class ServerMsgSender
  {
  protected:
    // Construction / destruction.
                    ServerMsgSender       ( void );
  public:
    virtual         ~ServerMsgSender      ( void );

  public:
    void            Send_StatusInfo       ( const Gw6cStatusInfo* aStatusInfo );
    void            Send_TunnelInfo       ( const Gw6cTunnelInfo* aTunnelInfo );
    void            Send_BrokerList       ( const Gw6cBrokerList* aBrokerList );
    void            Send_HAP6StatusInfo   ( const HAP6StatusInfo* aHAP6StatusInfo );

  protected:
    virtual void    PostMessage           ( Message* pMsg )=0;
  };

}

#endif
