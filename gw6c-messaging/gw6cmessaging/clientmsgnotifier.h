// **************************************************************************
// $Id: clientmsgnotifier.h,v 1.1 2007/02/23 21:30:25 cnepveu Exp $
//
// Copyright (c) 2007 Hexago Inc. All rights reserved.
// 
//   For license information refer to CLIENT-LICENSE.TXT
//
// Description:
//   Defines prototypes used by the messenger to notify the Gateway6 Client 
//   that a message has arrived and requires processing.
//
//   These functions need to be implemented in the Gateway6 Client.
//
// Author: Charles Nepveu
//
// Creation Date: November 2006
// __________________________________________________________________________
// **************************************************************************
#ifndef __gw6cmessaging_clientmsgnotifier_h__
#define __gw6cmessaging_clientmsgnotifier_h__


#include <gw6cmessaging/hap6msgdata.h>
#include <gw6cmessaging/gw6cuistrings.h>      // error_t definition & codes.


#ifdef __cplusplus
extern "C" {
#endif


error_t   NotifyHap6ConfigInfo  ( const HAP6ConfigInfo* aHAP6ConfigInfo );


#ifdef __cplusplus
}
#endif

#endif
