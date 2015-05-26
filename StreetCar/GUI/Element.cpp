#include "Element.h"

Element::Element(SDL_Renderer *r, SDL_Surface *s, bool dde) {
	pthread_mutex_init(&mutexRect, NULL);

	ren = r;
	dragDropEnable = dde;
	mouseHover = false;

	rect.x = 0;
	rect.y = 0;
	if (s == NULL) {
		rect.w = 0;
		rect.h = 0;
		surface = NULL;
	}
	else {
		rect.x = 0;
		rect.y = 0;
		rect.w = s->w;
		rect.h = s->h;
        surface = SDL_CreateRGBSurface(0, rect.w, rect.h, 32, 0, 0, 0, 0);
        SDL_BlitSurface(s, NULL, surface, NULL);
        texture = SDL_CreateTextureFromSurface(ren, surface);
	}
}

Element::~Element() {
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	pthread_mutex_destroy(&mutexRect);
}

void Element::setPosition(int x, int y) {
	pthread_mutex_lock(&mutexRect);

	rect.x = x;
	rect.y = y;

	pthread_mutex_unlock(&mutexRect);
}

bool Element::isIn(int x, int y) {

	bool in = false;
	pthread_mutex_lock(&mutexRect);

	if (x >= rect.x && x < rect.x + rect.w &&
		y >= rect.y && y < rect.y + rect.h)
		in = true;
		
	pthread_mutex_unlock(&mutexRect);

	return in;
}

void Element::print(int x, int y) {
	setPosition(x, y);
    SDL_RenderCopy(ren, texture, NULL, &rect);
}

SDL_Surface *Element::getSurface() {
	return surface;
}

SDL_Rect* Element::getRect(){
    return &rect;
}
