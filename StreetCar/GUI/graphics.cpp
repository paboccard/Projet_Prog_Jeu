#include "graphics.h"

//error message
void logSDLError(std::ostream &os, const std::string &msg){
    os << msg << " error: " << SDL_GetError() << std::endl;
}

void logTTFError(std::ostream &os, const std::string &msg){
    os << msg << " error: " << TTF_GetError() << std::endl;
}

//load texture of file in render
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren){
    //Initialize to NULL to avoid dangling pointer issues
    SDL_Texture *texture = NULL;
    //Load the image
    //SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
    SDL_Surface *loadedImage = IMG_Load(file.c_str());
    //If the loading went ok, convert to texture and return the texture
    if (loadedImage != NULL){
        texture = SDL_CreateTextureFromSurface(ren, loadedImage);
        SDL_FreeSurface(loadedImage);
        //Make sure converting went ok too
        if (texture == NULL){
            logSDLError(std::cout, "CreateTextureFromSurface");
        }
    }
    else {
        logSDLError(std::cout, "LoadBMP");
    }
    return texture;
}

//texture of render in position x y
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y){
    //Setup the destination rectangle to be at the position we want
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    //Query the texture to get its width and height to use
    SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
    SDL_RenderCopy(ren, tex, NULL, &dst);
}

// text in color using a police file
SDL_Texture* renderText(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer){
    //Open the font
    TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if (font == NULL){
        logSDLError(std::cout, "TTF_OpenFont");
        return NULL;
    }

    //render to a surface
    SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
    if (surf == NULL){
        TTF_CloseFont(font);
        logSDLError(std::cout, "TTF_RenderText");
        return NULL;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
    if (texture == NULL){
        logSDLError(std::cout, "CreateTexture");
    }

    //Clean up the surface and font
    SDL_FreeSurface(surf);
    //TTF_CloseFont(font);
    return texture;
}

//clean all
void cleanup(SDL_Renderer *render, SDL_Window *window, TTF_Font *font){
    TTF_CloseFont(font);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
}

void pause(){
    int continuer = 1;
    SDL_Event event;

    while (continuer){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

bool init(SDL_Window *window, SDL_Renderer *ren, TTF_Font *font){

    //starting SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        logSDLError(std::cout, "SDL_Init");
        return false;
    }

    //opening window
    window = SDL_CreateWindow("Streetcar",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,  SDL_WINDOW_SHOWN);
    if (window == NULL){
        logSDLError(std::cout, "SDL_CreateWindow");
        SDL_Quit();
        return false;
    }

    //create renderer
    ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL){
        SDL_DestroyWindow(window);
        logSDLError(std::cout, "SDL_CreateRenderer");
        SDL_Quit();
        return false;
    }

    //initialize ttf
    if (TTF_Init() != 0){
        cleanup(ren, window);
        logTTFError(std::cout, "TTF_Init");
        SDL_Quit();
        return false;
    }

    //Open the font
    font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if (font == NULL){
        logTTFError(std::cout, "TTF_OpenFont");
        return NULL;
    }

    return true;
}
