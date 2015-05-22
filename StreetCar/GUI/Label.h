#ifndef DEF_LABEL
#define DEF_LABEL

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include "Element.h"

class Label : public Element
{
	public:
        Label(SDL_Renderer *rend, std::string t, int w, int h, TTF_Font *ttf, SDL_Color color);
        ~Label();

	private:
		std::string text;
        TTF_Font *font;
        SDL_Color color;
};

#endif
