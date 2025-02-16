# PurrfectEngine
A Visual Novel engine coded in C++ with Lua as its scripting language!

# SDL 1.2 BRANCH REQUIREMENTS:

Windows: Windows 95+

Mac: Mac OS 9+

Please note that this branch doesn't support iOS (at least not yet)

# HOW TO COMPILE:

Get the dependencies (lua, sdl1.2, sdl_image, sdl_ttf and sdl_mixer), and compile.

# CMAKE:

Same instructions as the SDL2 branch, compile but don't forget to set your SDL path accordingly.


If you want to compile with Visual C++ 6, you can configure with:
```
cmake <path-to-source> -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=RelWithDebInfo
```
Then run nmake, don't forget to run (path to visual c++ 6)/BIN/VCVARS32.BAT x86!

# MAKEFILES:

Makefile.pc: Linux

Makefile.mac: macOS


# CREDITS:

90% Studios for the sprites, music, and background.
