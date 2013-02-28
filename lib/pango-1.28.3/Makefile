#parameter Device accept two value: OS or Simulator
LOCAL_PATH :=  .
APP_SUBDIRS := libs/iostreams/src
LOCAL_CPP_EXTENSION := .c
PREFIX = /Developer/Platforms/iPhoneOS.platform/Developer
target :=  pangocairo.a
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
INCPATH += -I"../glib/"
INCPATH += -I"../glib/glib"
INCPATH += -I"../glib/gobject"
INCPATH += -I"../glib/gmodule"
INCPATH += -I"../glib/android"
INCPATH += -I"../freetype-2.4.3/include"
INCPATH += -I"../fontconfig-2.8.0"
INCPATH += -I"../cairo-1.10.0/src"
#Build Switch
CFLAGS  += $(INCPATH) \
	-arch armv7 \
	-DHAVE_CONFIG_H \
	-DG_LOG_DOMAIN=\"Pango\" \
	-DPANGO_ENABLE_BACKEND \
	-DPANGO_ENABLE_ENGINE \
	-DSYSCONFDIR=\".\" \
	-DLIBDIR=\".\" \
	-DG_DISABLE_CAST_CHECKS \
	-DPANGO_MODULE_PREFIX=_pango_basic_fc \
	-I$(LOCAL_PATH)/pango \
	-I$(LOCAL_PATH) \
	$(NULL)

#sources := $(foreach F, $(APP_SUBDIRS), $(addprefix $(F)/,$(notdir $(wildcard $(LOCAL_PATH)/$(F)/*$(LOCAL_CPP_EXTENSION)))))

PANGO_SRC_FILES :=  \
	break.c					\
	ellipsize.c				\
	fonts.c					\
	glyphstring.c				\
	modules.c				\
	pango-attributes.c			\
	pango-bidi-type.c			\
	pango-color.c				\
	pango-context.c				\
	pango-coverage.c			\
	pango-engine.c				\
	pango-fontmap.c				\
	pango-fontset.c				\
	pango-glyph-item.c			\
	pango-gravity.c				\
	pango-item.c				\
	pango-language.c			\
	pango-layout.c				\
	pango-markup.c				\
	pango-matrix.c				\
	pango-renderer.c			\
	pango-script.c				\
	pango-tabs.c				\
	pango-utils.c				\
	reorder-items.c				\
	shape.c					\
	pango-enum-types.c			\
	module-defs-lang.c \
	$(NULL)

PANGO_FC_SRC_FILES :=  \
	pangofc-font.c	   	\
	pangofc-fontmap.c	\
	pangofc-decoder.c	\
	pangoft2.c \
	module-defs-fc.c	\
	pangoft2-fontmap.c	\
	pangoft2-render.c	\
	pango-ot-buffer.c	\
	pango-ot-info.c		\
	pango-ot-ruleset.c      \
	pango-ot-tag.c \
	$(NULL)

PANGO_CAIRO_SRC_FILES :=  \
 	pangocairo-context.c pangocairo-font.c \
	pangocairo-fontmap.c pangocairo-render.c \
	pangocairo-fcfont.c pangocairo-fcfontmap.c \


sources := \
	$(addprefix pango/, $(PANGO_SRC_FILES)) \
	$(addprefix pango/, $(PANGO_FC_SRC_FILES)) \
	$(addprefix pango/, $(PANGO_CAIRO_SRC_FILES)) \
	modules/basic/basic-fc.c \
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
%o : %cc
	$(CC) $(CFLAGS) -c -o $@ $<
# *.d files are treated as makefiles. This is a rule saying how to update them.

cleanall: clean cleandepends

clean:
	-rm -f $(modules)
	-rm -f $(target)


cleandepends:
	-rm -f $(depends)

