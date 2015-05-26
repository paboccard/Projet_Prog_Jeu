#include "Label.h"
#include "graphics.h"

using namespace std;

Label::Label(SDL_Renderer *ren, string t, int w, int h, TTF_Font *ttf, SDL_Color c) : Element(ren) {
    text = t;
    font = ttf;
    rect.w = w;
    rect.h = h;
    color = c;
    surface = TTF_RenderText_Blended(font, text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(ren, surface);
    //print(50, 50);
}

Label:: ~Label(){
    SDL_FreeSurface(surface);
}


