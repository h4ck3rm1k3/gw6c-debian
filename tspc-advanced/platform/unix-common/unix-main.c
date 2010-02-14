/*
-----------------------------------------------------------------------------
 $Id: unix-main.c,v 1.9 2008/03/14 15:50:46 cnepveu Exp $
-----------------------------------------------------------------------------
Copyright (c) 2001-2006 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT

-----------------------------------------------------------------------------
*/

#include "platform.h"
#include "gw6c_status.h"

#include <signal.h>

#include "tsp_client.h"
#include "hex_strings.h"
#include "log.h"
#include "os_uname.h"

#ifdef HAP6
#include "hap6.h"
#endif

extern int indSigHUP; /* Declared in every unix platform tsp_local.c */


/* --------------------------------------------------------------------------
// Signal handler function. KEEP THIS FUNCTION AS SIMPLE AS POSSIBLE.
*/
void signal_handler( int sigraised )
{
  if( sigraised == SIGHUP )
    indSigHUP = 1;
}


// --------------------------------------------------------------------------
// Retrieves OS information and puts it nicely in a string ready for display.
//
// Defined in tsp_client.h
//
void tspGetOSInfo( const size_t len, char* buf )
{
  if( len > 0  &&  buf != NULL )
  {
#ifdef OS_UNAME_INFO
    snprintf( buf, len, "Built on ///%s///", OS_UNAME_INFO );
#else
    snprintf( buf, len, "Built on ///unknown UNIX/BSD/Linux version///" );
#endif
  }
}


// --------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  int rc;
#ifdef HAP6
  hap6_status status = HAP6_STATUS_OK;
#endif
  /* Install new signal handler for HUP signal. */
  signal( SIGHUP, &signal_handler );

#ifdef HAP6
  /* Initialize the HAP6 module. */
  status = hap6_initialize();

  if (status != HAP6_STATUS_OK) {
    DirectErrorMessage(HAP6_LOG_PREFIX_ERROR HEX_STR_HAP6_ERR_CANT_INIT_MODULE);
    return ERR_HAP6_INIT;
  }
#endif

  /* entry point */
  rc = tspMain(argc, argv);

#ifdef HAP6
  /* The HAP6 module destructs (deinitialization). */
  status = hap6_destruct();

  if (status != HAP6_STATUS_OK)
  {
    DirectErrorMessage(HAP6_LOG_PREFIX_ERROR HEX_STR_HAP6_ERR_CANT_DO_SHUTDOWN);
  }
#endif

  return rc;
}
