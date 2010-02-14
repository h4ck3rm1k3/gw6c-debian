# ###########################################################################
#
# $Id: Makefile,v 1.25 2008/02/29 17:23:33 cnepveu Exp $
#
#  Copyright (c) 2007 Hexago Inc. All rights reserved.
#
#  For license information refer to CLIENT-LICENSE.TXT
#
# Author: Charles Nepveu
#
# ###########################################################################
#

OBJ_DIR=objs
BIN_DIR=bin
LIB_DIR=lib
INC_DIR=gw6cconfig
TARGET=$(LIB_DIR)/libgw6cconfig.a

GW6CPAL=../gw6c-pal
GW6CPALINC_DIR=$(GW6CPAL)/out_inc
GW6CPALDEFS_DIR=$(GW6CPAL)/defs
GW6CPALLIB_DIR=$(GW6CPAL)/out_lib
GW6CPALLIB=gw6cpal

CC=gcc
CXX=g++
LD=g++
RANLIB=ranlib
AR=ar

ifdef DEBUG
CXXFLAGS=-g -I. -I$(GW6CPALINC_DIR) -I$(GW6CPALDEFS_DIR) -Wall -D_REENTRANT -DDEBUG $(HAP6_DEFINES) $(EXTRA_CXXFLAGS)
CFLAGS=-g -I. -I$(GW6CPALINC_DIR) -I$(GW6CPALDEFS_DIR) -Wall -D_REENTRANT -DDEBUG $(HAP6_DEFINES) $(EXTRA_CFLAGS)
LDFLAGS=-g -L$(LIB_DIR) -L$(GW6CPALLIB_DIR) -lgw6cconfig -l$(GW6CPALLIB) $(EXTRA_LDFLAGS)
else
CXXFLAGS=-O2 -I. -I$(GW6CPALINC_DIR) -I$(GW6CPALDEFS_DIR) -Wall -D_REENTRANT -DNDEBUG $(HAP6_DEFINES) $(EXTRA_CXXFLAGS)
CFLAGS=-O2 -I. -I$(GW6CPALINC_DIR) -I$(GW6CPALDEFS_DIR) -Wall -D_REENTRANT -DNDEBUG $(HAP6_DEFINES) $(EXTRA_CFLAGS)
LDFLAGS=-O2 -L$(LIB_DIR) -L$(GW6CPALLIB_DIR) -lgw6cconfig -l$(GW6CPALLIB) $(EXTRA_LDFLAGS)
endif


.PHONY: all clean test_targets

#
#
all: $(TARGET) $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

OBJS=$(OBJ_DIR)/namevalueparser.o \
	$(OBJ_DIR)/config.o \
	$(OBJ_DIR)/namevalueconfig.o \
	$(OBJ_DIR)/gw6cvalidation.o \
	$(OBJ_DIR)/gw6cconfig.o \
	$(OBJ_DIR)/gw6c_c_wrapper.o \
	$(OBJ_DIR)/gw6cuistrings.o \
	$(OBJ_DIR)/hap6_devmap_c_wrap.o \
	$(OBJ_DIR)/hap6devicemappingconfig.o


$(OBJ_DIR)/namevalueparser.o: src/namevalueparser.cc $(INC_DIR)/namevalueparser.h
	$(CXX) $(CXXFLAGS) -c -o $(OBJ_DIR)/namevalueparser.o src/namevalueparser.cc

$(OBJ_DIR)/config.o: src/config.cc $(INC_DIR)/config.h
	$(CXX) $(CXXFLAGS) -c -o $(OBJ_DIR)/config.o src/config.cc

$(OBJ_DIR)/namevalueconfig.o: src/namevalueconfig.cc $(INC_DIR)/namevalueconfig.h
	$(CXX) $(CXXFLAGS) -c -o $(OBJ_DIR)/namevalueconfig.o src/namevalueconfig.cc

$(OBJ_DIR)/gw6cvalidation.o: src/gw6cvalidation.cc $(INC_DIR)/gw6cvalidation.h
	$(CXX) $(CXXFLAGS) -c -o $(OBJ_DIR)/gw6cvalidation.o src/gw6cvalidation.cc

$(OBJ_DIR)/gw6cconfig.o: src/gw6cconfig.cc $(INC_DIR)/gw6cconfig.h
	$(CXX) $(CXXFLAGS) -c -o $(OBJ_DIR)/gw6cconfig.o src/gw6cconfig.cc

$(OBJ_DIR)/gw6c_c_wrapper.o: src/gw6c_c_wrapper.cc $(INC_DIR)/gw6c_c_wrapper.h
	$(CXX) $(CXXFLAGS) -c -o $(OBJ_DIR)/gw6c_c_wrapper.o src/gw6c_c_wrapper.cc

$(OBJ_DIR)/gw6cuistrings.o: src/gw6cuistrings.c $(INC_DIR)/gw6cuistrings.h
	$(CC) $(CFLAGS) -c -o $(OBJ_DIR)/gw6cuistrings.o src/gw6cuistrings.c

$(OBJ_DIR)/test_namevalue.o: src/test_namevalue.cc
	$(CXX) $(CXXFLAGS) -c -o $(OBJ_DIR)/test_namevalue.o src/test_namevalue.cc

$(OBJ_DIR)/test_c_wrapper.o: src/test_c_wrapper.c
	$(CC) $(CFLAGS) -c -o $(OBJ_DIR)/test_c_wrapper.o src/test_c_wrapper.c

$(OBJ_DIR)/hap6_devmap_c_wrap.o: src/hap6_devmap_c_wrap.cc
	$(CXX) $(CXXFLAGS) -c -o $(OBJ_DIR)/hap6_devmap_c_wrap.o src/hap6_devmap_c_wrap.cc

$(OBJ_DIR)/hap6devicemappingconfig.o: src/hap6devicemappingconfig.cc
	$(CXX) $(CXXFLAGS) -c -o $(OBJ_DIR)/hap6devicemappingconfig.o src/hap6devicemappingconfig.cc

test_targets: $(TARGET) $(OBJ_DIR)/test_namevalue.o $(OBJ_DIR)/test_c_wrapper.o $(BIN_DIR)
	$(LD) -o $(BIN_DIR)/test_namevalue $(OBJ_DIR)/test_namevalue.o $(LDFLAGS)
	$(LD) -o $(BIN_DIR)/test_c_wrapper $(OBJ_DIR)/test_c_wrapper.o $(LDFLAGS)
	

$(TARGET): $(OBJ_DIR) $(OBJS) $(LIB_DIR)
	$(AR) cru $(TARGET) $(OBJS)
	$(RANLIB) $(TARGET)

clean:
	@echo -n "Cleaning up workspace... "
	@rm -rf $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR)
	@echo "done."
