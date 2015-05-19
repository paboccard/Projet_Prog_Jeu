#ifndef DEF_BUTTON
#define DEF_BUTTON

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include "Element.h"

class Button : public Element
{
	public:
		Button(std::string t, int w, int h);
		std::string getText() {return text;};
		SDL_Texture *getTexture(SDL_Renderer *rend);
		int w() {return width;};
		int h() {return height;};
		SDL_Rect *getRect();


	private:
		SDL_Surface *surface;
		std::string text;
};

#endif
