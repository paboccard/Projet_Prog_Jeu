#include "ButtonMenu.h"

using namespace std;

ButtonMenu::ButtonMenu(SDL_Renderer *ren, string t, int w, int h, TTF_Font *ttf) : Element(ren) {
    text = t;
    font = ttf;
    rect.w = w;
    rect.h = h;
    labelElem = new Label(ren, text.c_str(), w, h, font, (SDL_Color) { 255, 0, 0 });
    imageTrain = new Image(ren, "images/train.bmp", 20, 10);
    surface = SDL_CreateRGBSurface(0, rect.w, rect.h, 32, 0, 0, 0, 0);

    labelElem->setPosition(20,0);
    texture = SDL_CreateTextureFromSurface(ren, surface);
    mouseExit();
}

ButtonMenu:: ~ButtonMenu(){
 
}

void ButtonMenu::mouseEnter() {
	mouseHover = true;
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0,0,255));
    SDL_BlitSurface(labelElem->getSurface(),NULL, surface, labelElem->getRect());
    SDL_BlitSurface(imageTrain->getSurface(),NULL, surface, imageTrain->getRect());
    SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch);
}

void ButtonMenu::mouseExit(){
	mouseHover = false;
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0,0,255));
    SDL_BlitSurface(labelElem->getSurface(),NULL, surface, labelElem->getRect());
    SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch);
}

void ButtonMenu::mouseClicked(){
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 255, 0));
    surface = TTF_RenderText_Blended(font, text.c_str(), (SDL_Color){ 0, 255, 255, 255 });
    SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch);
}

void ButtonMenu::mousePressed(){
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 255, 0));
    surface = TTF_RenderText_Blended(font, text.c_str(), (SDL_Color){ 255, 0, 0, 255 });
    SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch);
}

void ButtonMenu::mouseReleased(){
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 255, 0));
    surface = TTF_RenderText_Blended(font, text.c_str(), (SDL_Color){ 255, 0, 255, 255 });
    SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch);
}
