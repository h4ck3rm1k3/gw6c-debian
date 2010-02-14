// **************************************************************************
// $Id: pipeio.h,v 1.5 2008/01/08 19:33:57 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
// 
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Defines a specialized way of transferring data using IPC: Pipes!
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cmessaging_pipeio_h__
#define __gw6cmessaging_pipeio_h__


#include <gw6cmessaging/ipcservent.h>
#include <gw6cmessaging/gw6cuistrings.h>


namespace gw6cmessaging
{
  // ------------------------------------------------------------------------
  class PipeIO : virtual public IPCServent
  {
  public:
    // Construction / destruction
                    PipeIO                ( void );
    virtual         ~PipeIO               ( void );

    // Overrides from IPC Servent
    virtual error_t CanRead               ( bool &bCanRead ) const;   // Non-Blocking
    virtual error_t CanWrite              ( bool &bCanWrite ) const;  // Non-Blocking

    virtual error_t Read                  ( void* pvReadBuffer, 
                                            const uint32_t nBufferSize, 
                                            uint32_t& nRead );          // Blocking
    virtual error_t Write                 ( const void* pvData, 
                                            const uint32_t nDataSize, 
                                            uint32_t& nWritten );       // Blocking
  };

}

#endif
