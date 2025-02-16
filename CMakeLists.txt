cmake_minimum_required(VERSION 3.10)

# set the project name
project(PurrfectEngine)

set(TARGET PurrfectEngine)

# add the executable
# Create an option to switch between a system sdl library and a vendored sdl library

add_executable(${TARGET} WIN32 src/main.cpp src/Engine/Engine.cpp src/LuaRead/LuaRead.cpp)
include(FindSDL)
include(FindSDL_image)
include(FindSDL_ttf)
include(FindSDL_mixer)


set(SDL_INCLUDE_DIR "C:/SDL-1.2.14/include")

set(SDL_LIBRARY  "C:/SDL-1.2.14/lib")

set(SDL_IMAGE_LIBRARIES "C:/SDL-1.2.14/lib")

set(SDL_IMAGE_INCLUDE_DIRS "C:/SDL-1.2.14/include")

set(SDL_TTF_LIBRARIES "C:/SDL-1.2.14/lib")

set(SDL_TTF_INCLUDE_DIRS "C:/SDL-1.2.14/include")

set(SDL_MIXER_LIBRARIES "C:/SDL-1.2.14/lib")

set(SDL_MIXER_INCLUDE_DIRS "C:/SDL-1.2.14/include")


Find_Package(SDL REQUIRED)
Find_Package(SDL_image REQUIRED)
Find_Package(SDL_ttf REQUIRED)
Find_Package(SDL_mixer REQUIRED)



target_include_directories(PurrfectEngine PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/GameInclude"
                          "C:/SDL-1.2.14/include"
                          )

                          
# Link your executable to the Lua library
# Ensure Lua is built before your project
add_subdirectory(lua)
target_link_libraries(${TARGET} PRIVATE lua_static SDLmain  SDL  SDL_image SDL_ttf SDL_mixer)


