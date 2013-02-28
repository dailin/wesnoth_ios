#parameter Device accept two value: OS or Simulator
LOCAL_PATH :=  .
APP_SUBDIRS := libs/iostreams/src
LOCAL_CPP_EXTENSION := .c
PREFIX = /Developer/Platforms/iPhoneOS.platform/Developer
target :=  xml2.a
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
	-DHAVE_CONFIG_H \
	-I$(LOCAL_PATH)/include \
	$(NULL)

#sources := $(foreach F, $(APP_SUBDIRS), $(addprefix $(F)/,$(notdir $(wildcard $(LOCAL_PATH)/$(F)/*$(LOCAL_CPP_EXTENSION)))))

sources := 	\
	SAX.c entities.c encoding.c error.c \
	parserInternals.c parser.c tree.c hash.c list.c xmlIO.c \
	xmlmemory.c uri.c valid.c xlink.c HTMLparser.c HTMLtree.c \
	debugXML.c xpath.c xpointer.c xinclude.c nanohttp.c nanoftp.c \
	DOCBparser.c catalog.c globals.c threads.c c14n.c xmlstring.c \
	xmlregexp.c xmlschemas.c xmlschemastypes.c xmlunicode.c \
	xmlreader.c relaxng.c dict.c SAX2.c xmlwriter.c legacy.c \
	chvalid.c pattern.c xmlsave.c xmlmodule.c schematron.c \
	triostr.c trio.c trionan.c \
	$(NULL)
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

