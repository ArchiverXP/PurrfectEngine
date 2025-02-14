
#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Game.h"
#include "Engine.h"
#include <iostream>

/* We will use this renderer to draw into this window every frame. */

int state = 2;

Game game;

Engine eng;


/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    SDL_SetAppMetadata("Purrfect Engine", "1.0", "com.archiverxp.paengine");
    eng.InitEngine();
    SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1"); 
    eng.ReadLuaScript("scripts/1.lua");
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
    }

    if(event->type == SDL_EVENT_FINGER_DOWN){
        eng.lua["Part"]();
        
        eng.lua.set("state", state++);
    }


    if(event->type == SDL_EVENT_KEY_DOWN){
        
        eng.lua["Part"]();

        eng.lua.set("state", state++);

        
    }
    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void *appstate)
{
    eng.Refresh();

    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    eng.ExitGame();
    return;
}

