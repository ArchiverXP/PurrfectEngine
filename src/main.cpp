
 /* use the callbacks instead of main() */
#include <SDL/SDL.h>
#include "Game.h"
#include "Engine.h"
#include <iostream>

#include <fstream>  

/* We will use this renderer to draw into this window every frame. */

int state = 2;

Game game;

Engine eng;


/* This function runs once at startup. */


int main(int argc, char* argv[]){
    eng.InitEngine();
    eng.ReadLuaScript("scripts/1.lua");
    
    SDL_Event event;

    Uint8 done = 0;


    while(!done)
    {
        
        while(SDL_PollEvent(&event) )
        {


            if(event.type == SDL_KEYDOWN){
                eng.lua["Part"]();
        
                eng.lua.set("state", state++);

            }

            else if(event.type == SDL_QUIT){
                    eng.ExitGame();
                    return 0;

            }

        } 

        eng.Refresh();
    }

	return 0;
	
}