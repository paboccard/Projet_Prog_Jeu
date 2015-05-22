#include "Label.h"

using namespace std;

Label::Label(SDL_Renderer *ren, std::string t, int w, int h, TTF_Font *ttf, SDL_Color c) : Element(ren) {
    text = t;
    font = ttf;
    rect.w = w;
    rect.h = h;
    surface = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
    color = c;
}

Label:: ~Label(){

}


