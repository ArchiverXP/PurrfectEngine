#include "LuaRead.h"

Engine engine;


LuaRead::LuaRead(){

}

int LuaRead::LoadBackground_L(lua_State* L){

    lua_getglobal(L, "LoadBG");
    
    std::string bg = luaL_checkstring(L, 1); //1 argument

    engine.LoadBG(bg);

    return 0;

}

int LuaRead::LoadSpr_L(lua_State* L){

    lua_getglobal(L, "LoadSprite");

    std::string spr = luaL_checkstring(L, 1); //1 argument

    float x = luaL_checkinteger(L, 2);

    float y = luaL_checkinteger(L, 3);

    engine.LoadImage(spr, x, y);

    return 0;

}

int LuaRead::LoadTextBox_L(lua_State* L){

    lua_getglobal(L, "LoadTBox");

    std::string txtbox = luaL_checkstring(L, 1); //1 argument

    engine.LoadTextbox(txtbox);

    return 0;

}

int LuaRead::ShowDia_L(lua_State* L){

    lua_getglobal(L, "CharSay");

    std::string dialog = luaL_checkstring(L, 1); //1 argument

    float x = luaL_checkinteger(L, 2);

    float y = luaL_checkinteger(L, 3);

    engine.ShowDialog(dialog, x, y);

    return 0;

}


int LuaRead::PlayMus_L(lua_State* L){

    lua_getglobal(L, "PlayMus");

    std::string mus = luaL_checkstring(L, 1); //1 argument

    engine.PlayMusic(mus);

    return 0;

}

void LuaRead::LoadPart(){

    lua_getglobal(L, "Part");
    
    if(lua_isfunction(L, -1)){
        lua_pcall(L, 0, 1, 0);
    }
    else{
        printf("Error: %s", lua_tostring(L,-1));
    }

    //eng.lua.set("state", state++);
}

void LuaRead::ReadLuaFromFile(const char* file){
    
    std::cout << file;

    L = luaL_newstate();

    luaopen_base(L);

    luaL_openlibs(L);

    lua_pushcfunction(L, LoadBackground_L);

    lua_setglobal(L, "LoadBG");

    lua_pushcfunction(L, LoadSpr_L);

    lua_setglobal(L, "LoadSprite");

    lua_pushcfunction(L, LoadTextBox_L);

    lua_setglobal(L, "LoadTBox");

    lua_pushcfunction(L, ShowDia_L);

    lua_setglobal(L, "CharSay");

    lua_pushcfunction(L, PlayMus_L);

    lua_setglobal(L, "PlayMus");


    if(luaL_dofile(L, file) == LUA_OK){
        std::cout << "Successfully read file!\n";


        
    }
    else{
        std::cout << "Oops, the file wasn't read.";
        printf("Error: %s", lua_tostring(L,-1));
    }
}