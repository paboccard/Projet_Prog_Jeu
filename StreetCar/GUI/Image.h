#ifndef DEF_IMAGE
#define DEF_IMAGE

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include "Element.h"

class Image : public Element
{
	public:
        Image(SDL_Renderer *rend, const std::string &imageFile, int w, int h);
        ~Image();

	private:
        TTF_Font *img;

};

#endif
