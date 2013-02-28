#parameter Device accept two value: OS or Simulator
LOCAL_PATH :=  .
APP_SUBDIRS := .
LOCAL_CPP_EXTENSION := .c
PREFIX = /Developer/Platforms/iPhoneOS.platform/Developer

SDKVER = 5.0
SDK = $(PREFIX)/SDKs/iPhoneOS$(SDKVER).sdk

CC := $(PREFIX)/usr/bin/llvm-gcc-4.2
#CC := $(PREFIX)/usr/llvm-gcc-4.2/bin/llvm-gcc-4.2
LD := $(CC)
LIBTOOL :=$(PREFIX)/usr/bin/libtool
AR := $(PREFIX)/usr/bin/ar
RANLIB :=  $(PREFIX)/usr/bin/ranlib
##INCLUDE PATH For apple
INCPATH += -I"$(SDK)/usr/include"
INCPATH += -I"$(PREFIX)/usr/lib/gcc/arm-apple-darwin10/4.2.1/include"
INCPATH += -I"$(PREFIX)/usr/include"
INCPATH += -I"."
#Build Switch
CFLAGS  += $(INCPATH) \
	-arch armv7

sources := $(foreach F, $(APP_SUBDIRS), $(addprefix $(F)/,$(notdir $(wildcard $(LOCAL_PATH)/$(F)/*$(LOCAL_CPP_EXTENSION)))))


target :=  libbz2.a

modules :=  $(sources:$(LOCAL_CPP_EXTENSION)=.o)

all: $(target)

$(target): $(modules)
	$(AR) rvc $@ $?
	$(RANLIB) $@

%o : %cpp
	$(CC) $(CFLAGS) -c -o $@ $<
%o : %c
	$(CC) $(CFLAGS) -c -o $@ $<
# *.d files are treated as makefiles. This is a rule saying how to update them.

cleanall: clean cleandepends

clean:
	-rm -f $(modules)
	-rm -f $(target)


cleandepends:
	-rm -f $(depends)

