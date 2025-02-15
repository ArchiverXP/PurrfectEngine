
#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "LuaRead.h"
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

        SDL_Renderer *render2;

        SDL_Rect dst;

        void Refresh();
        
        void ExitGame();
        
        void LoadImage(std::string image, float x, float y);

        void ShowDialog(std::string dialog,  float x, float y);

        void LoadBG(std::string image);

        void LoadTextbox(std::string image);

        void PlayMusic(std::string mus);

        void ReadLuaScript(std::string file);

        
        void ClearEverythingButBG();

        static bool setSet();

        void StateSetter();

        void EventKey();


};