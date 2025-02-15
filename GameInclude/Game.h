
#pragma once
#include "SDL.h"
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