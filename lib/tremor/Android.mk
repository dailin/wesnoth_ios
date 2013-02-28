LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := tremor

LOCAL_EXPORT_C_INCLUDES := \
	$(LOCAL_PATH)/include \
	$(LOCAL_PATH)/include/tremor \
	$(NULL)

LOCAL_CFLAGS := \
	-I$(LOCAL_PATH) \
	-I$(LOCAL_PATH)/include/tremor \
	-DHAVE_ALLOCA_H 

LOCAL_CPP_EXTENSION := .cpp

LOCAL_SRC_FILES := $(notdir $(wildcard $(LOCAL_PATH)/*.c))

LOCAL_LIBRARIES := ogg

LOCAL_SHARED_LIBRARIES := $(filter-out $(APP_AVAILABLE_STATIC_LIBS), $(LOCAL_LIBRARIES))
LOCAL_STATIC_LIBRARIES := $(filter $(APP_AVAILABLE_STATIC_LIBS), $(LOCAL_LIBRARIES))

LOCAL_LDLIBS := 

ifeq (,$(findstring $(LOCAL_MODULE), $(APP_AVAILABLE_STATIC_LIBS)))
include $(BUILD_SHARED_LIBRARY)
else
include $(BUILD_STATIC_LIBRARY)
endif