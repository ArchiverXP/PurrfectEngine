


#pragma once
#ifdef __cplusplus
  extern "C" {
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
  }
#endif //__cplusplus

#include <iostream>
#include "Engine.h"

class LuaRead
{
public:
    LuaRead();

    lua_State* L;

    void ReadLuaFromFile(const char* file);

    static int LoadBackground_L(lua_State* L);

    static int LoadTextBox_L(lua_State* L);

    static int LoadSpr_L(lua_State* L);

    static int ShowDia_L(lua_State* L);

    static int PlayMus_L(lua_State* L);

    void LoadPart();
    
};