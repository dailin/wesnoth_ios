#parameter Device accept two value: OS or Simulator
LOCAL_PATH :=  .
APP_SUBDIRS := libs/iostreams/src
LOCAL_CPP_EXTENSION := .c
PREFIX = /Developer/Platforms/iPhoneOS.platform/Developer
target :=  libfreetype.a
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
	-DFT_CONFIG_OPTION_SYSTEM_ZLIB \
	-DFT_CONFIG_CONFIG_H="<ftconfig.h>" \
	-DHAVE_CONFIG_H \
	-DDARWIN_NO_CARBON \
	-DFT_CONFIG_OPTION_SYSTEM_ZLIB \
	-DFT_CONFIG_CONFIG_H="<ftconfig.h>" \
	-DFT2_BUILD_LIBRARY \
	-DFT_CONFIG_MODULES_H="<ftmodule.h>" \
	-I$(LOCAL_PATH)/include \
	-I$(LOCAL_PATH)/include/freetype/config \
	$(NULL)

#sources := $(foreach F, $(APP_SUBDIRS), $(addprefix $(F)/,$(notdir $(wildcard $(LOCAL_PATH)/$(F)/*$(LOCAL_CPP_EXTENSION)))))

SRC_FILES :=  \
	base/ftsystem.c \
	base/ftdebug.c \
	base/ftinit.c \
	base/ftbase.c \
	base/ftbbox.c \
	base/ftbdf.c \
	base/ftbitmap.c \
	base/ftcid.c \
	base/ftfstype.c \
	base/ftgasp.c \
	base/ftglyph.c \
	base/ftgxval.c \
	base/ftlcdfil.c \
	base/ftmm.c \
	base/ftotval.c \
	base/ftpatent.c \
	base/ftpfr.c \
	base/ftstroke.c \
	base/ftsynth.c \
	base/fttype1.c \
	base/ftwinfnt.c \
	base/ftxf86.c \
	truetype/truetype.c \
	type1/type1.c \
	cff/cff.c \
	cid/type1cid.c \
	pfr/pfr.c \
	type42/type42.c \
	winfonts/winfnt.c \
	pcf/pcf.c \
	bdf/bdf.c \
	sfnt/sfnt.c \
	autofit/autofit.c \
	pshinter/pshinter.c \
	raster/raster.c \
	smooth/smooth.c \
	cache/ftcache.c \
	gzip/ftgzip.c \
	lzw/ftlzw.c \
	psaux/psaux.c \
	psnames/psnames.c \
	$(NULL)

sources := $(addprefix src/, $(SRC_FILES))
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

