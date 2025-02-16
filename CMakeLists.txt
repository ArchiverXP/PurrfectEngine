cmake_minimum_required(VERSION 3.10)

# set the project name
project(PurrfectEngine)

set(TARGET PurrfectEngine)

set(SDL2_DIR "C:/SDL2")
# add the executable
# Create an option to switch between a system sdl library and a vendored sdl library
option(PurrfectEngine "Use vendored libraries" ON)

set(CMAKE_PREFIX_PATH C:/SDL)

find_package(SDL2 REQUIRED CONFIG REQUIRED)

add_executable(${TARGET} WIN32 src/main.cpp src/Engine/Engine.cpp src/LuaRead/LuaRead.cpp)


target_include_directories(PurrfectEngine PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/GameInclude"
                          )

                          
# Link your executable to the Lua library
# Ensure Lua is built before your project
add_subdirectory(lua)
target_link_libraries(${TARGET} PRIVATE lua_static SDL2::SDL2 SDL2main SDL2_image SDL2_mixer SDL2_ttf)


