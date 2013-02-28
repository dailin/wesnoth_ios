#parameter Device accept two value: OS or Simulator
LOCAL_PATH :=  .
APP_SUBDIRS := libs/iostreams/src
LOCAL_CPP_EXTENSION := .c
PREFIX = /Developer/Platforms/iPhoneOS.platform/Developer
target :=  libcairo.a
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
INCPATH += -I"../pixman-0.21.2/pixman"
INCPATH += -I"../freetype-2.4.3/include"
INCPATH += -I"../fontconfig-2.8.0/fontconfig"
INCPATH += -I"../libpng-1.4.4/include/libpng14"

#Build Switch
CFLAGS  += $(INCPATH) \
	-arch armv7 \
	-isysroot /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS5.0.sdk/ \
	-DHAVE_CONFIG_H \
	-D_REENTRANT \
	-DCAIRO_NO_MUTEX=1 \
	-I$(LOCAL_PATH)/src \
	$(NULL)

#sources := $(foreach F, $(APP_SUBDIRS), $(addprefix $(F)/,$(notdir $(wildcard $(LOCAL_PATH)/$(F)/*$(LOCAL_CPP_EXTENSION)))))

SRC_FILES :=  \
	cairo-analysis-surface.c \
	cairo-arc.c \
	cairo-array.c \
	cairo-atomic.c \
	cairo-base64-stream.c \
	cairo-base85-stream.c \
	cairo-bentley-ottmann.c \
	cairo-bentley-ottmann-rectangular.c \
	cairo-bentley-ottmann-rectilinear.c \
	cairo-botor-scan-converter.c \
	cairo-boxes.c \
	cairo.c \
	cairo-cache.c \
	cairo-clip.c \
	cairo-color.c \
	cairo-composite-rectangles.c \
	cairo-debug.c \
	cairo-device.c \
	cairo-fixed.c \
	cairo-font-face.c \
	cairo-font-face-twin.c \
	cairo-font-face-twin-data.c \
	cairo-font-options.c \
	cairo-freelist.c \
	cairo-freed-pool.c \
	cairo-gstate.c \
	cairo-hash.c \
	cairo-hull.c \
	cairo-image-info.c \
	cairo-image-surface.c \
	cairo-lzw.c \
	cairo-matrix.c \
	cairo-recording-surface.c \
	cairo-misc.c \
	cairo-mutex.c \
	cairo-observer.c \
	cairo-output-stream.c \
	cairo-paginated-surface.c \
	cairo-path-bounds.c \
	cairo-path.c \
	cairo-path-fill.c \
	cairo-path-fixed.c \
	cairo-path-in-fill.c \
	cairo-path-stroke.c \
	cairo-pattern.c \
	cairo-pen.c \
	cairo-polygon.c \
	cairo-rectangle.c \
	cairo-rectangular-scan-converter.c \
	cairo-region.c \
	cairo-rtree.c \
	cairo-scaled-font.c \
	cairo-slope.c \
	cairo-spans.c \
	cairo-spline.c \
	cairo-stroke-style.c \
	cairo-surface.c \
	cairo-surface-fallback.c \
	cairo-surface-clipper.c \
	cairo-surface-offset.c \
	cairo-surface-snapshot.c \
	cairo-surface-subsurface.c \
	cairo-surface-wrapper.c \
	cairo-system.c \
	cairo-tor-scan-converter.c \
	cairo-toy-font-face.c \
	cairo-traps.c \
	cairo-unicode.c \
	cairo-user-font.c \
	cairo-version.c \
	cairo-wideint.c \
	cairo-cff-subset.c \
	\
	cairo-scaled-font-subsets.c \
	cairo-truetype-subset.c \
	cairo-type1-fallback.c \
	cairo-type1-subset.c \
	cairo-type3-glyph-surface.c \
	\
	cairo-pdf-operators.c \
	\
	cairo-png.c \
	\
	cairo-ft-font.c \
	\
	cairo-ps-surface.c \
	\
	cairo-svg-surface.c \
	\
	$(NULL)

	#cairo-xml-surface.c \

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

