# ###########################################################################
# $Id: Makefile,v 1.3 2008/02/29 17:24:32 cnepveu Exp $
#
# This source code copyright (c) Hexago Inc. 2002-2007.
#
#  For license information refer to CLIENT-LICENSE.TXT
#
# ###########################################################################
#
# NOTE: This makefile MUST be interpreted by GNU make.

# Include the platform makefile, if it exists.
-include platform.mak

ifdef DEBUG
CFLAGS=-g -Wall $(CC_INC_PATHS) $(PLATFORM_CFLAGS) -D_REENTRANT -DDEBUG
LDFLAGS=-g $(LD_LIB_PATHS) $(LD_LIBRARIES) -lsocket -lnsl -lcrypto -lpthread -lstdc++ -L/usr/sfw/lib -L/usr/local/ssl/lib
else
CFLAGS=-O2 -Wall $(CC_INC_PATHS) $(PLATFORM_CFLAGS) -D_REENTRANT
LDFLAGS=$(LD_LIB_PATHS) $(LD_LIBRARIES) -lsocket -lnsl -lcrypto -lpthread -lstdc++ -L/usr/sfw/lib -L/usr/local/ssl/lib
endif
CC=gcc

OBJS=$(OBJS_DIR)/tsp_local.o 


all: $(TARGET)
install: all


$(OBJS_DIR)/tsp_local.o:tsp_local.c
	$(CC) $(CFLAGS) -c tsp_local.c -o $(OBJS_DIR)/tsp_local.o $(DEFINES)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(wildcard $(OBJS_DIR)/*.o) $(LDFLAGS)

clean:
	rm -f $(OBJS) $(TARGET)
