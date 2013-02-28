#parameter Device accept two value: OS or Simulator
LOCAL_PATH :=  .
APP_SUBDIRS := libs/iostreams/src
LOCAL_CPP_EXTENSION := .c
PREFIX = /Developer/Platforms/iPhoneOS.platform/Developer
target :=  SDL_mixer.a
SDKVER = 5.0
SDK = $(PREFIX)/SDKs/iPhoneOS$(SDKVER).sdk

CC := $(PREFIX)/usr/bin/llvm-gcc-4.2
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
	-arch armv7 \
	-I$(LOCAL_PATH) \
	-I$(LOCAL_PATH)/include \
	-I$(LOCAL_PATH)/timidity \
	-I../SDL-1.3/include \
	-I../flac-1.2.1/include \
	-I../mikmod/include \
	-I../tremor/include \
	-I../libogg-1.2.2/include \
	-DWAV_MUSIC \
	-DOGG_USE_TREMOR \
	-DOGG_MUSIC \
	-DFLAC_MUSIC \
	-DMOD_MUSIC \
	-DMID_MUSIC \
	-DUSE_TIMIDITY_MIDI \
	-DOGG_USE_TREMOR \
	$(NULL)

sources := $(notdir $(wildcard $(LOCAL_PATH)/*.c)) $(addprefix timidity/, $(notdir $(wildcard $(LOCAL_PATH)/timidity/*.c)))

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

