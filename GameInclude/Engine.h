
#pragma once
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "sol.hpp"
#include <string>
#include <vector>
#include <iostream>


class Engine
{
public:
        Engine();

        


        void InitEngine();

        void InitWindSurf();

        int loaded;

        int i;

        sol::state lua;

        SDL_Rect dst;

        void Refresh();
        
        void ExitGame();
        
        static void LoadImage(std::string image, float x, float y);

        static void ShowDialog(std::string dialog,  float x, float y);

        static void LoadBG(std::string image);

        static void LoadTextbox(std::string image);

        static void PlayMusic(std::string mus);

        void ReadLuaScript(std::string file);

        static void ClearText();

        static bool setSet();

        void StateSetter();

        void EventKey();


};