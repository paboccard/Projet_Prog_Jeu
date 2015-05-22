#ifndef DEF_BUTTON
#define DEF_BUTTON

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include "Element.h"

class Button : public Element
{
	public:
        Button(SDL_Renderer *rend, std::string t, int w, int h, TTF_Font *ttf);
        ~Button();
        void mouseEnter();
        void mouseExit();
        void mouseClicked();
        void mousePressed();
        void mouseReleased();

	private:
		std::string text;
        TTF_Font *font;
};

#endif
