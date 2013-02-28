#parameter Device accept two value: OS or Simulator
LOCAL_PATH :=  .
APP_SUBDIRS := libs/iostreams/src
LOCAL_CPP_EXTENSION := .c
PREFIX = /Developer/Platforms/iPhoneOS.platform/Developer
target :=  libintl.a
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
	-DLOCALEDIR=\"\" \
	-DLOCALE_ALIAS_PATH=\"\" \
	-DLIBDIR=\"\" \
	-DBUILDING_LIBINTL \
	-DBUILDING_DLL \
	-DIN_LIBINTL \
	-DHAVE_STPCPY \
	-DENABLE_RELOCATABLE=1 \
	-DIN_LIBRARY \
	-DINSTALLDIR=\"\" \
	-DNO_XMALLOC \
	-Dset_relocation_prefix=libintl_set_relocation_prefix \
	-Drelocate=libintl_relocate \
	-DDEPENDS_ON_LIBICONV=1 \
	-DHAVE_CONFIG_H \
	-I$(LOCAL_PATH)/gettext-runtime/intl \
	-I$(LOCAL_PATH)/gettext-runtime \
	$(NULL)

#sources := $(foreach F, $(APP_SUBDIRS), $(addprefix $(F)/,$(notdir $(wildcard $(LOCAL_PATH)/$(F)/*$(LOCAL_CPP_EXTENSION)))))

SRC_FILES :=  \
	bindtextdom.c \
	dcgettext.c \
	dgettext.c \
	gettext.c \
	finddomain.c \
	hash-string.c \
	loadmsgcat.c \
	localealias.c \
	textdomain.c \
	l10nflist.c \
	explodename.c \
	dcigettext.c \
	dcngettext.c \
	dngettext.c \
	ngettext.c \
	plural.c \
	plural-exp.c \
	localcharset.c \
	threadlib.c \
	lock.c \
	relocatable.c \
	langprefs.c \
	localename.c \
	log.c \
	printf.c \
	setlocale.c \
	version.c \
	osdep.c \
	intl-compat.c \
	$(NULL)

sources := $(addprefix gettext-runtime/intl/, $(SRC_FILES))
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

