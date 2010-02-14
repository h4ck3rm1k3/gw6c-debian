/*
---------------------------------------------------------------------------
 $Id: icmpapi.h,v 1.2 2007/05/02 13:32:21 cnepveu Exp $
---------------------------------------------------------------------------
  Copyright (c) 2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT.
---------------------------------------------------------------------------
*/

#ifndef _ICMP_INCLUDED_
#define _ICMP_INCLUDED_

HANDLE
WINAPI
IcmpCreateFile(
    VOID
    );
BOOL
WINAPI
IcmpCloseHandle(
    HANDLE  IcmpHandle
    );

DWORD
WINAPI
IcmpSendEcho(
    HANDLE                   IcmpHandle,
    IPAddr                   DestinationAddress,
    LPVOID                   RequestData,
    WORD                     RequestSize,
    PIP_OPTION_INFORMATION   RequestOptions,
    LPVOID                   ReplyBuffer,
    DWORD                    ReplySize,
    DWORD                    Timeout
    );



DWORD
WINAPI
IcmpSendEcho2(
    HANDLE                   IcmpHandle,
    HANDLE                   Event,
#ifdef PIO_APC_ROUTINE_DEFINED
    PIO_APC_ROUTINE          ApcRoutine,
#else
    FARPROC                  ApcRoutine,
#endif
    PVOID                    ApcContext,
    IPAddr                   DestinationAddress,
    LPVOID                   RequestData,
    WORD                     RequestSize,
    PIP_OPTION_INFORMATION   RequestOptions,
    LPVOID                   ReplyBuffer,
    DWORD                    ReplySize,
    DWORD                    Timeout
    );

DWORD
IcmpParseReplies(
    LPVOID                   ReplyBuffer,
    DWORD                    ReplySize
    );


#endif // _ICMP_INCLUDED_
