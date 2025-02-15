
#pragma once
#include <SDL/SDL.h>
#define SOL_NO_THREAD_LOCAL

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>


class Game
{
public:
    Game();

    void init();
    
    bool changeset();
    bool hack1;
    int arg;

    SDL_Surface* gScreenSurface = NULL;
    

};