
#include "Engine.h"


#define SCREEN_W 1280
#define SCREEN_H 720



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

SDL_Surface* BGSurface = NULL;

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

    InitWindSurf(&window, &renderer);
    


}

void Engine::InitWindSurf(SDL_Window **winns, SDL_Renderer **rennie){
    SDL_Init(SDL_INIT_AUDIO);
    SDL_CreateWindowAndRenderer(1280, 720, SDL_WINDOW_RESIZABLE,  winns, rennie);
    IMG_Init(IMG_INIT_PNG);
    

    std::cout << SDL_GetError();
    

    
}

void Engine::LoadBG(std::string image){

    std::string image_PNG = "img/" + image + ".png";

    epicsurface = IMG_Load(image_PNG.c_str());

    test23 = SDL_CreateTextureFromSurface(renderer, epicsurface);

    targetBG = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 1280, 720);

    SDL_SetTextureScaleMode(targetBG, SDL_ScaleModeBest);

    SDL_SetRenderTarget(renderer, targetBG);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_TRANSPARENT);

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, test23, NULL, NULL);

    SDL_QueryTexture(test23, NULL, NULL, &rect3.w, &rect3.h);

    rect3.x = 0;
    rect3.y = 0;

    

    if(!test23){
        std::cout << "hey kid you didn't do the rendering right\n" << SDL_GetError();
    }

}


void Engine::LoadTextbox(std::string image){



    std::string image_PNG = "img/" + image + ".png";

    epicersurface = IMG_Load(image_PNG.c_str());

    TB = SDL_CreateTextureFromSurface(renderer, epicersurface);

    targetTB = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA4444, SDL_TEXTUREACCESS_TARGET, 1280, 720);

    SDL_SetTextureScaleMode(targetTB, SDL_ScaleModeBest);
    
    SDL_SetRenderTarget(renderer, targetTB);

    SDL_SetTextureBlendMode(targetTB, SDL_BLENDMODE_BLEND);

    SDL_RenderCopy(renderer, TB, NULL, NULL);



    SDL_QueryTexture(TB, NULL, NULL, &rectangle.w, &rectangle.h);



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
    
    SDL_SetTextureScaleMode(text2, SDL_ScaleModeBest);

    targetTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 720, 1280);

    SDL_SetTextureScaleMode(targetTexture, SDL_ScaleModeBest);
    
    SDL_SetRenderTarget(renderer, targetTexture);

    SDL_SetTextureBlendMode(targetTexture, SDL_BLENDMODE_BLEND);


    SDL_RenderCopy(renderer, text2, NULL, NULL);

    SDL_QueryTexture(text2, NULL, NULL, &rect2.w, &rect2.h);



    rect2.x = x;
    rect2.y = y;

    if(!text2){
        std::cout << "hey kid you didn't do the rendering right\n" << SDL_GetError();
    }

}

void Engine::Refresh(){

    SDL_SetRenderTarget(renderer, NULL);
    
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, targetBG, NULL, &rect3);

    SDL_RenderCopy(renderer, targetTexture, NULL, &rect2);

    SDL_RenderCopy(renderer, targetTB, NULL, &rectangle);

    SDL_RenderCopy(renderer, targetLayer2, NULL, &rect);


    SDL_RenderSetLogicalSize(renderer, 1280, 720);

    SDL_RenderPresent(renderer);


}

void Engine::ExitGame(){

    SDL_DestroyTexture(targetTexture);


    SDL_DestroyTexture(targetLayer2);


    SDL_DestroyTexture(targetBG);


    SDL_DestroyTexture(targetTB);

    IMG_Quit();

    SDL_Quit();

    TTF_Quit();

    SDL_DestroyWindow(window);



}

void Engine::ShowDialog(std::string dialog, float x, float y){

    TTF_Init();

    TTF_Font* Bani = TTF_OpenFont("fonts/Bani-Regular.ttf", 30);

    SDL_Color White = {255, 255, 255};

    SDL_Surface* dialog2 = TTF_RenderText_Blended_Wrapped(Bani, dialog.c_str(), White, 0);

    Texture2 = SDL_CreateTextureFromSurface(renderer, dialog2);

    SDL_SetTextureScaleMode(Texture2, SDL_ScaleModeBest);
    
    targetLayer2 = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 720, 1280);

    SDL_SetRenderTarget(renderer, targetLayer2);

    SDL_SetTextureBlendMode(targetLayer2, SDL_BLENDMODE_BLEND);

    SDL_RenderCopy(renderer, Texture2, NULL, NULL);

    SDL_QueryTexture(Texture2, NULL, NULL, &rect.w, &rect.h);

    


    std::cout << SDL_GetError();

    rect.x = x;
    rect.y = y;


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


void Engine::EventKey(){

    StateSetter();
}