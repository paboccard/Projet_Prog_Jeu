#include "Button.h"

using namespace std;

Button::Button(SDL_Renderer *ren, std::string t, int w, int h, TTF_Font *ttf) : Element(ren) {
    text = t;
    font = ttf;
    rect.w = w;
    rect.h = h;
    surface = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
    mouseExit();
}

Button:: ~Button(){

}

void Button::mouseEnter(){
	mouseHover = true;
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 255, 0));
    surface = TTF_RenderText_Blended(font, text.c_str(), (SDL_Color){ 0, 0, 255, 255 });
    SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch);
}

void Button::mouseExit(){
	mouseHover = false;
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 255, 0));
    surface = TTF_RenderText_Blended(font, text.c_str(), (SDL_Color){ 0, 0, 0, 0 });
    SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch);
}

void Button::mouseClicked(){
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 255, 0));
    surface = TTF_RenderText_Blended(font, text.c_str(), (SDL_Color){ 0, 255, 255, 255 });
    SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch);
}

void Button::mousePressed(){
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 255, 0));
    surface = TTF_RenderText_Blended(font, text.c_str(), (SDL_Color){ 255, 0, 0, 255 });
    SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch);
}

void Button::mouseReleased(){
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 255, 0));
    surface = TTF_RenderText_Blended(font, text.c_str(), (SDL_Color){ 255, 0, 255, 255 });
    SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch);
}
