# $Id: Makefile,v 1.6 2008/01/09 15:08:49 cnepveu Exp $
#
#  Copyright (c) 2007 Hexago Inc. All rights reserved.
#
#  For license information refer to CLIENT-LICENSE.TXT
#

all:

install:
	@echo Installing man pages
	@mkdir -p $(INSTALL_MAN)/man5
	@mkdir -p $(INSTALL_MAN)/man8
	@cp man5/gw6c.conf.5 $(INSTALL_MAN)/man5
	@cp man8/gw6c.8 $(INSTALL_MAN)/man8
	@echo "To view man pages, run :"
	@echo "    man -M $(INSTALL_MAN) gw6c"
	@echo "    man -M $(INSTALL_MAN) gw6c.conf"

clean: 
