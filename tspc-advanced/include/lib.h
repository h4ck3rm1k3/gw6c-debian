/*
-----------------------------------------------------------------------------
 $Id: lib.h,v 1.18 2008/01/09 15:08:46 cnepveu Exp $
-----------------------------------------------------------------------------
  Copyright (c) 2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT.
-----------------------------------------------------------------------------
*/

#ifndef _LIB_H_
#define _LIB_H_

/* globals */

#define IPv4Addr    ".0123456789"
#define IPv6Addr    "ABCDEFabcdef:0123456789"
#define IPAddrAny   "ABCDEFabcdef:.0123456789"
#define Numeric     "0123456789"

/* exports */

sint32_t            IsAll                 ( char *, char * );
sint32_t            IsPresent             ( char * );
char*               tspGetErrorByCode     ( sint32_t code );
sint32_t            IsAddressInPrefix     ( const char* address, const char* prefix, const sint16_t prefix_len );

#endif
