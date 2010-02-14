/*
-----------------------------------------------------------------------------
 $Id: cli.h,v 1.10 2008/03/13 19:52:09 cnepveu Exp $
-----------------------------------------------------------------------------
  Copyright (c) 2007 Hexago Inc. All rights reserved.

  For license information refer to CLIENT-LICENSE.TXT.
-----------------------------------------------------------------------------
*/

#ifndef _CLI_H_
#define _CLI_H_

sint32_t            ask                   (char *question, ...);
void                ParseArguments        (sint32_t, char *[], tConf *);

#endif
