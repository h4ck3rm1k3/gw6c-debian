# ###########################################################################
#
# $Id: Makefile,v 1.15 2008/01/09 15:08:43 cnepveu Exp $
#
#  For license information refer to CLIENT-LICENSE.TXT
#
# ###########################################################################
#
# NOTE: This makefile MUST be interpreted by GNU make.

# Include the platform makefile, if it exists.
-include $(PLATFORM_DIR)/$(PLATFORM)/platform.mak


all:

install: check-env gw6c.conf.sample

.PHONY: all install check-env gw6c.conf.sample clean


check-env:
	@[ -n "$(PLATFORM)" ] || { echo "Platform is undefined." ; exit 1 ; }
	@[ -n "$(INSTALL_DIR)" ] || { echo "Installation directory is undefined." ; exit 1 ; }

gw6c.conf.sample:
	@echo Generating basic configuration file
	@[ ! -f $(BIN_DIR)/gw6c.conf.sample ] || { \
	    rm -f $(BIN_DIR)/gw6c.conf.sample; \
	}
	@sed -e "s+@ifname_v4v6@+$(PLATFORM_V4V6)+" \
	     -e "s+@ifname_v6udpv4@+$(PLATFORM_V6UDPV4)+" \
	     -e "s+@ifname_v6v4@+$(PLATFORM_V6V4)+" \
	     -e "s+@conf_template@+$(PLATFORM)+" \
	     -e "s+@conf_gw6_dir@+$(INSTALL_DIR)+" \
	     gw6c.conf.in > $(BIN_DIR)/gw6c.conf.sample
	@chmod 700 $(BIN_DIR)/gw6c.conf.sample

clean:
	rm -f $(BIN_DIR)/gw6c.conf.sample
