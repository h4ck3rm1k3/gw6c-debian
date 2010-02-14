// **************************************************************************
// $Id: ipcserver.h,v 1.5 2007/01/30 18:53:26 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
// 
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Defines a generic IPC Server.
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cmessaging_ipcserver_h__
#define __gw6cmessaging_ipcserver_h__


#include <gw6cmessaging/ipcservent.h>


namespace gw6cmessaging
{
  // ------------------------------------------------------------------------
  class IPCServer : virtual public IPCServent
  {
  protected:
    // Construction / destruction
                    IPCServer             ( void );
  public:
    virtual         ~IPCServer            ( void );

    // IPC Servent overrides.
    virtual error_t Initialize            ( void );   // Blocking
    virtual error_t UnInitialize          ( void );   // Blocking
    virtual bool    WaitReady             ( unsigned long ulWaitms );

    // IPC Server operations.
    virtual error_t CreateConnectionPoint ( void ) = 0;   // Non-Blocking
    virtual error_t AcceptConnection      ( void ) = 0;   // Blocking
    virtual error_t CloseConnection       ( void ) = 0;   // Non-Blocking
  };

}

#endif
