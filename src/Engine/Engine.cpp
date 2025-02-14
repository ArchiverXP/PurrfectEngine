
#include "Game.h"
#include "Engine.h"


#define SCREEN_W 1280
#define SCREEN_H 720

Game gamer;

Engine::Engine(){

}

SDL_Window* window = NULL;

SDL_Texture* Texture2 = NULL;

SDL_Renderer* renderer = NULL;

SDL_Texture* texture = NULL;

SDL_Texture* text2 = NULL;

SDL_Texture* test23 = NULL;

SDL_Texture* TB = NULL;

SDL_Texture* targetTexture = NULL;

SDL_Texture* targetLayer2 = NULL;

SDL_Texture* targetBG = NULL;

SDL_Texture* targetTB = NULL;

SDL_Surface* epicsurface = NULL;

SDL_Surface* epicersurface = NULL;

static Mix_Music *music = NULL;

SDL_FRect estRect;

SDL_FRect rect;

SDL_FRect rect2;

SDL_FRect rect3;

SDL_FRect rectangle;


void Engine::InitEngine(){


    std::cout << "Initializing Engine...\n";

    std::cout << "Initializing Window and Renderer\n";
    
    std::cout << SDL_GetError();

    InitWindSurf(&window, &renderer);
    

    std::cout << "Renderer: \n" << SDL_GetRendererName(renderer);


}

void Engine::InitWindSurf(SDL_Window **winns, SDL_Renderer **rennie){
    SDL_Init(SDL_INIT_AUDIO);
    SDL_CreateWindowAndRenderer("Example Purrfect Engine Project", 1280, 720, SDL_WINDOW_RESIZABLE,  winns, rennie);

    

    
}

void Engine::LoadBG(std::string image, float x, float y){

    std::string image_PNG = "img/" + image + ".png";

    epicsurface = IMG_Load(image_PNG.c_str());

    test23 = SDL_CreateTextureFromSurface(renderer, epicsurface);

    targetBG = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, test23->w, test23->h);

    SDL_SetRenderTarget(renderer, targetBG);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_TRANSPARENT);

    SDL_RenderClear(renderer);

    SDL_RenderTexture(renderer, test23, NULL, NULL);

    SDL_GetTextureSize(test23, &rect3.w, &rect3.h);

    rect3.x = x;
    rect3.y = y;
    rect3.w = SCREEN_W;
    rect3.h = SCREEN_H;

    if(!test23){
        std::cout << "hey kid you didn't do the rendering right\n" << SDL_GetError();
    }

}


void Engine::LoadTextbox(std::string image){



    std::string image_PNG = "img/" + image + ".png";

    epicersurface = IMG_Load(image_PNG.c_str());

    TB = SDL_CreateTextureFromSurface(renderer, epicersurface);

    targetTB = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA4444, SDL_TEXTUREACCESS_TARGET, TB->w, TB->h);

    SDL_SetTextureScaleMode(TB, SDL_SCALEMODE_LINEAR);

    SDL_SetRenderTarget(renderer, targetTB);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_TRANSPARENT);

    SDL_RenderClear(renderer);

    SDL_RenderTexture(renderer, TB, NULL, NULL);

    SDL_GetTextureSize(TB, &rectangle.w, &rectangle.h);


    rectangle.x = 0;
    rectangle.y = SCREEN_H / 1.33;



    if(!epicersurface){
        std::cout << "hey kid you didn't do the rendering right\n" << SDL_GetError();
    }

}
void Engine::LoadImage(std::string image, float x, float y){

    estRect = {720, 1280, 0, 0};

    std::string image_PNG = "img/" + image + ".png";

    epicsurface = IMG_Load(image_PNG.c_str());

    text2 = SDL_CreateTextureFromSurface(renderer, epicsurface);

    targetTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, text2->w, text2->h);

    SDL_SetRenderTarget(renderer, targetTexture);


    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_TRANSPARENT);

    SDL_RenderClear(renderer);

    SDL_RenderTexture(renderer, text2, NULL, NULL);

    SDL_GetTextureSize(text2, &rect2.w, &rect2.h);


    rect2.x = x;
    rect2.y = y;

    if(!text2){
        std::cout << "hey kid you didn't do the rendering right\n" << SDL_GetError();
    }

}

void Engine::Refresh(){

    SDL_SetRenderTarget(renderer, NULL);
    
    SDL_RenderClear(renderer);

    SDL_RenderTexture(renderer, targetBG, NULL, &rect3);

    SDL_RenderTexture(renderer, targetTexture, NULL, &rect2);

    SDL_RenderTexture(renderer, targetTB, NULL, &rectangle);

    SDL_RenderTexture(renderer, targetLayer2, NULL, &rect);


    SDL_SetRenderLogicalPresentation(renderer, 1280, 720, SDL_LOGICAL_PRESENTATION_STRETCH);

    SDL_RenderPresent(renderer);


}

void Engine::ExitGame(){

    SDL_DestroyTexture(targetTexture);


    SDL_DestroyTexture(targetLayer2);


    SDL_DestroyTexture(targetBG);


    SDL_DestroyTexture(targetTB);


}

void Engine::ShowDialog(std::string dialog, float x, float y){

    TTF_Init();

    TTF_Font* Bani = TTF_OpenFont("fonts/Bani-Regular.ttf", 30);

    SDL_Color White = {255, 255, 255};

    SDL_Surface* dialog2 = TTF_RenderText_Blended_Wrapped(Bani, dialog.c_str(), 0, White, 0);

    Texture2 = SDL_CreateTextureFromSurface(renderer, dialog2);

    targetLayer2 = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, Texture2->w, Texture2->h);

    SDL_SetRenderTarget(renderer, targetLayer2);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_TRANSPARENT);

    SDL_RenderClear(renderer);

    SDL_RenderTexture(renderer, Texture2, NULL, NULL);

    SDL_GetTextureSize(Texture2, &rect.w, &rect.h);

    


    std::cout << SDL_GetError();

    rect.x = x;
    rect.y = y;


}

void Engine::PlayMusic(std::string mus){
    Mix_Init(MIX_INIT_FLAC);
    SDL_AudioSpec spec;
    spec.freq = MIX_DEFAULT_FREQUENCY;
    spec.format = MIX_DEFAULT_FORMAT;
    spec.channels = MIX_DEFAULT_CHANNELS;

    


    if(!Mix_OpenAudio(0,&spec)){
        std::cout << SDL_GetError();
    }
    else{
        Mix_QuerySpec(&spec.freq, &spec.format, &spec.channels);


        music = Mix_LoadMUS(mus.c_str());

        if(!music){
            std::cout << SDL_GetError();
        }
        else{
            Mix_PlayMusic(music, 99999);
        }
    }
}


void Engine::StateSetter(){
    i++;
}


void Engine::ReadLuaScript(std::string file){
    

    lua.open_libraries(sol::lib::base);

	lua.set_function("LoadBG", &Engine::LoadBG);

    lua.set_function("LoadSprite", &Engine::LoadImage);

    lua.set_function("LoadTBox", &Engine::LoadTextbox);

    lua.set_function("CharSay", &Engine::ShowDialog);

    lua.set_function("PlayMus", &Engine::PlayMusic);


    lua.script_file(file);
    


}

void Engine::EventKey(){

    StateSetter();
}