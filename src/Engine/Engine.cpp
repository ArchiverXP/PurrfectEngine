
#include "Game.h"
#include "Engine.h"


#define SCREEN_W 1280
#define SCREEN_H 720

Game gamer;

Engine::Engine(){

}

SDL_Surface* screen = NULL;

SDL_Surface* epicsurface = NULL;

SDL_Surface* epicersurface = NULL;

SDL_Surface* BGSurface = NULL;

SDL_Surface* dialog2 = NULL;

static Mix_Music *music = NULL;

SDL_Rect estRect;

SDL_Rect rect;

SDL_Rect rect2;

SDL_Rect rect3;

SDL_Rect rectangle;


void Engine::InitEngine(){


    std::cout << "Initializing Engine...\n";

    std::cout << "Initializing Window and Renderer\n";
    
    std::cout << SDL_GetError();

    InitWindSurf();
    


}

void Engine::InitWindSurf(){
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    SDL_WM_SetCaption("Purrfect Engine (SDL 1.2)", NULL);
    
    screen = SDL_SetVideoMode(1280, 720, 0, SDL_RESIZABLE);

    IMG_Init(IMG_INIT_PNG);

    std::cout << SDL_GetError();
    

    
}

void Engine::LoadBG(std::string image){

    std::string image_PNG = "img/" + image + ".png";

    BGSurface = IMG_Load(image_PNG.c_str());


    SDL_BlitSurface(BGSurface, NULL, screen, &rect3);

    rect3.x = 0;
    rect3.y = 0;

    if(!BGSurface){
        std::cout << "hey kid you didn't do the rendering right\n" << SDL_GetError();
    }

}


void Engine::LoadImage(std::string image, float x, float y){

    std::string image_PNG = "img/" + image + ".png";

    epicsurface = IMG_Load(image_PNG.c_str());


    SDL_BlitSurface(epicsurface, NULL, screen, &rect2);


    rect2.x = x;
    rect2.y = y;

    if(!epicsurface){
        std::cout << "hey kid you didn't do the rendering right\n" << SDL_GetError();
    }

}



void Engine::LoadTextbox(std::string image){



    std::string image_PNG = "img/" + image + ".png";

    epicersurface = IMG_Load(image_PNG.c_str());


    rectangle.x = 0;
    rectangle.y = 500;


    SDL_BlitSurface(epicersurface, NULL, screen, &rectangle);

    if(!epicersurface){
        std::cout << "hey kid you didn't do the rendering right\n" << SDL_GetError();
    }

}




void Engine::Refresh(){

    SDL_Flip(screen);


}

void Engine::ExitGame(){

    SDL_FreeSurface(epicsurface);


    IMG_Quit();

    SDL_Quit();

    TTF_Quit();



}

void Engine::ShowDialog(std::string dialog, float x, float y){

    TTF_Init();

    TTF_Font* Bani = TTF_OpenFont("fonts/Bani-Regular.ttf", 30);

    SDL_Color White = {255, 255, 255};


    rect.x = x;
    rect.y = y;

    dialog2 = TTF_RenderText_Blended(Bani, dialog.c_str(), White);

    SDL_BlitSurface(dialog2, NULL, screen, &rect);
    
    std::cout << SDL_GetError();


}

void Engine::PlayMusic(std::string mus){
    Mix_Init(MIX_INIT_OGG);
    if (Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0){
        std::cout << "Pingus";
    }
    music = Mix_LoadMUS(mus.c_str());

    if(!music){
        std::cout << SDL_GetError();
    }
    else{
        Mix_PlayMusic(music, 99999);
    }
}


void Engine::StateSetter(){
    i++;
}

void Engine::ClearText(){
    SDL_BlitSurface(BGSurface, NULL, screen, &rect3);
    SDL_BlitSurface(epicsurface, NULL, screen, &rect2);
    SDL_BlitSurface(epicersurface, NULL, screen, &rectangle);

}

void Engine::ReadLuaScript(std::string file){
    

    lua.open_libraries(sol::lib::base);

	lua.set_function("LoadBG", &Engine::LoadBG);

    lua.set_function("LoadSprite", &Engine::LoadImage);

    lua.set_function("LoadTBox", &Engine::LoadTextbox);

    lua.set_function("CharSay", &Engine::ShowDialog);

    lua.set_function("PlayMus", &Engine::PlayMusic);

    lua.set_function("ClearTxt", &Engine::ClearText);


    lua.script_file(file);
    


}

void Engine::EventKey(){

    StateSetter();
}