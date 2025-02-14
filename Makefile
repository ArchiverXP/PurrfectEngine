THEOS_DEVICE_IP = 127.0.0.1
THEOS_DEVICE_PORT = 2222
TARGET := iphone:clang:latest:5.1
ARCHS = armv7 
include $(THEOS)/makefiles/common.mk

APPLICATION_NAME = PurrfectEngine




PurrfectEngine_FILES = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
PurrfectEngine_LIBRARIES = lua
PurrfectEngine_FRAMEWORKS = UIKit CoreGraphics MobileCoreServices QuartzCore CoreAudio AudioToolbox OpenGLES Foundation SDL3 SDL3_image SDL3_ttf SDL3_mixer

PurrfectEngine_CCFLAGS =  -IGameInclude --std=c++17 -I/usr/local/include/lua 

include $(THEOS_MAKE_PATH)/application.mk
