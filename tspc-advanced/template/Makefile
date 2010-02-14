# ###########################################################################
#
# $Id: Makefile,v 1.11 2008/01/09 15:09:17 cnepveu Exp $
#
#  This source code copyright (c) Hexago Inc. 2005,2007.
#
#  LICENSE NOTICE: You may use and modify this source code only if you
#  have executed a valid license agreement with Hexago Inc. granting
#  you the right to do so, the said license agreement governing such
#  use and modifications.   Copyright or other intellectual property
#  notices are not to be removed from the source code.
#
# ###########################################################################
#

all:

install:
	@echo "Installing templates ..."
	@for template_var in README $(PLATFORM).sh; do \
            cp $${template_var} $(INSTALL_TEMPL)/$${template_var}; \
        done

clean: 
