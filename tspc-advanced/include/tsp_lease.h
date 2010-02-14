/*
-----------------------------------------------------------------------------
 $Id: tsp_lease.h,v 1.8 2008/03/13 19:52:11 cnepveu Exp $
-----------------------------------------------------------------------------
  Copyright (c) 2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT.
-----------------------------------------------------------------------------
*/

#ifndef _TSP_LEASE_H_
#define _TSP_LEASE_H_

long                tspLeaseGetExpTime    ( const long tun_lifetime );

sint32_t            tspLeaseCheckExp      ( const long tun_expiration );

#endif
