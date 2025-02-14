
#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "sol.hpp"
#include <string>
#include <vector>
#include <iostream>


class Engine
{
public:
        Engine();

        


        void InitEngine();

        void InitWindSurf(SDL_Window **winns, SDL_Renderer **rennie);

        int loaded;

        int i;

        sol::state lua;

        SDL_Renderer *render2;

        std::vector<SDL_Surface*> epicsurf2;

        std::vector<SDL_Texture*> epicTexture;

        SDL_Rect dst;

        void Refresh();
        
        void ExitGame();
        
        static void LoadImage(std::string image, float x, float y);

        static void ShowDialog(std::string dialog,  float x, float y);

        static void LoadBG(std::string image);

        static void LoadTextbox(std::string image);

        static void PlayMusic(std::string mus);

        void ReadLuaScript(std::string file);

        void ClearEverythingButBG();

        static bool setSet();

        void StateSetter();

        void EventKey();


};