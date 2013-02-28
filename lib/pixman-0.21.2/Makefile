#parameter Device accept two value: OS or Simulator
LOCAL_PATH :=  .
APP_SUBDIRS := libs/iostreams/src
LOCAL_CPP_EXTENSION := .c
PREFIX = /Developer/Platforms/iPhoneOS.platform/Developer
target :=  libpixman.a
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
	-DPIXMAN_NO_TLS \
	-D_USE_MATH_DEFINES \
	-I$(LOCAL_PATH)/pixman \
	$(NULL)

#sources := $(foreach F, $(APP_SUBDIRS), $(addprefix $(F)/,$(notdir $(wildcard $(LOCAL_PATH)/$(F)/*$(LOCAL_CPP_EXTENSION)))))

SRC_FILES :=  \
	pixman-access.c				\
	pixman-access-accessors.c		\
	pixman-cpu.c				\
	pixman-gradient-walker.c		\
	pixman-region16.c			\
	pixman-region32.c			\
	pixman-image.c				\
	pixman-implementation.c			\
	pixman-combine32.c			\
	pixman-combine64.c			\
	pixman-general.c			\
	pixman.c				\
	pixman-fast-path.c			\
	pixman-solid-fill.c			\
	pixman-conical-gradient.c		\
	pixman-linear-gradient.c		\
	pixman-radial-gradient.c		\
	pixman-bits-image.c			\
	pixman-utils.c				\
	pixman-edge.c				\
	pixman-edge-accessors.c			\
	pixman-trap.c				\
	pixman-timer.c				\
	pixman-matrix.c \
	$(NULL)
sources := $(addprefix pixman/, $(SRC_FILES))
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

