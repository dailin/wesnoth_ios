#parameter Device accept two value: OS or Simulator
LOCAL_PATH :=  .
APP_SUBDIRS := libs/iostreams/src
LOCAL_CPP_EXTENSION := .c
PREFIX = /Developer/Platforms/iPhoneOS.platform/Developer
target :=  libflac.a
SDKVER = 5.0
SDK = $(PREFIX)/SDKs/iPhoneOS$(SDKVER).sdk

CC := $(PREFIX)/usr/bin/llvm-gcc-4.2
LD := $(CC)
LIBTOOL :=$(PREFIX)/usr/bin/libtool
AR := $(PREFIX)/usr/bin/ar
RANLIB :=  $(PREFIX)/usr/bin/ranlib
##INCLUDE PATH For apple
#INCPATH += -I"$(SDK)/usr/include"
#INCPATH += -I"$(PREFIX)/usr/lib/gcc/arm-apple-darwin10/4.2.1/include"
#INCPATH += -I"$(PREFIX)/usr/include"
INCPATH += -I"."
INCPATH += -I"../libogg-1.2.2/include/"
#Build Switch
CFLAGS  += $(INCPATH) \
	-arch armv7 \
	-isysroot /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS5.0.sdk \
	-DHAVE_CONFIG_H \
	-DPNG_CONFIGURE_LIBPNG \
	$(NULL)

#sources := $(foreach F, $(APP_SUBDIRS), $(addprefix $(F)/,$(notdir $(wildcard $(LOCAL_PATH)/$(F)/*$(LOCAL_CPP_EXTENSION)))))

SRC_FILES :=  \
	png.c \
	pngset.c \
	pngget.c \
	pngrutil.c \
	pngtrans.c \
	pngwutil.c \
	pngread.c \
	pngrio.c \
	pngwio.c \
	pngwrite.c \
	pngrtran.c \
	pngwtran.c \
	pngmem.c \
	pngerror.c \
	pngpread.c \
	$(NULL)

sources := $(addprefix , $(SRC_FILES))
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

