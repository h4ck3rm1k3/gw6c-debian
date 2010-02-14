// **************************************************************************
// $Id: ipcservent.h,v 1.10 2008/01/08 19:33:56 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
// 
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Defines a generic IPC servent. A servent may be a Server or Client.
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cmessaging_ipcservent_h__
#define __gw6cmessaging_ipcservent_h__


#include <pal.h>
#include <gw6cmessaging/gw6cuistrings.h>
#include <gw6cmessaging/semaphore.h>

typedef ptr_t*                IPC_HANDLE;
#define INVALID_IPC_HANDLE    ((IPC_HANDLE)-1)

namespace gw6cmessaging
{
  // ------------------------------------------------------------------------
  class IPCServent
  {
  protected:
    IPC_HANDLE      m_Handle;         // IPC Handle for Connection & IO operations.
    Semaphore*      m_pSemReadyState; // Semaphore released when ready state is reached.

  protected:
    // Construction / destruction
                    IPCServent            ( void ) : m_Handle(INVALID_IPC_HANDLE), 
                                                     m_pSemReadyState(0) {};
  public:
    virtual         ~IPCServent           ( void ) { };

    // Connection operations.
    virtual error_t Initialize            ( void )=0;             // Blocking
    virtual error_t UnInitialize          ( void )=0;             // Blocking
    virtual bool    WaitReady             ( unsigned long ulWaitms )=0;

    // IO operations
    virtual error_t CanRead               ( bool& bCanRead ) const = 0;   // Non-Blocking
    virtual error_t CanWrite              ( bool& bCanWrite ) const = 0;  // Non-Blocking
    virtual error_t Read                  ( void* pvReadBuffer, 
                                            const uint32_t nBufferSize, 
                                            uint32_t& nRead )=0;    // Blocking
    virtual error_t Write                 ( const void* pvData, 
                                            const uint32_t nDataSize, 
                                            uint32_t& nWritten )=0; // Blocking
  };

}

#endif
