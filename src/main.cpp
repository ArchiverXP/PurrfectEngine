
 /* use the callbacks instead of main() */
#include "SDL.h"
#include "Game.h"
#include "Engine.h"
#include <iostream>

#include <fstream>  

/* We will use this renderer to draw into this window every frame. */

int state = 2;

Game game;

Engine eng;

LuaRead lua;


/* This function runs once at startup. */


int main(int argc, char* argv[]){
    eng.InitEngine();
    lua.ReadLuaFromFile("scripts/1.lua");
    
    SDL_Event event;

    Uint8 done = 0;


    while(!done)
    {
        
        while(SDL_PollEvent(&event) )
        {

            if(event.type == SDL_FINGERDOWN){

                lua.LoadPart();
               //engine.ShowDialog("YAY SUCCESS!!! YEEEEEAHHHH", 160.0, 490.0);
               
            }

            if(event.type == SDL_KEYDOWN){
                lua.LoadPart();

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