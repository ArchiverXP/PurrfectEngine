THEOS_DEVICE_IP = 127.0.0.1
THEOS_DEVICE_PORT = 2222
TARGET := iphone:clang:latest:5.1
ARCHS = armv7 
include $(THEOS)/makefiles/common.mk

APPLICATION_NAME = PurrfectEngine




PurrfectEngine_FILES = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
PurrfectEngine_LIBRARIES = lua SDL2 SDL2_image SDL2_ttf SDL2_mixer
PurrfectEngine_FRAMEWORKS = UIKit CoreGraphics MobileCoreServices ImageIO QuartzCore CoreAudio AudioToolbox OpenGLES Foundation 

PurrfectEngine_CCFLAGS =  -IGameInclude --std=c++17 -I/usr/local/include -I/usr/include/SDL2 -Isol

include $(THEOS_MAKE_PATH)/application.mk
