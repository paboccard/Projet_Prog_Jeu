#include <iostream> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
 
const int SCREEN_WIDTH  = 950;
const int SCREEN_HEIGHT = 600;

 //error message
void logSDLError(std::ostream &os, const std::string &msg);
void logTTFError(std::ostream &os, const std::string &msg);

//load texture of file in render
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);

//texture of render in position x y
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);

// text in color using a police file
SDL_Texture* renderText(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer);

//clean all
void cleanup(SDL_Renderer *render, SDL_Window *window, TTF_Font *font);


