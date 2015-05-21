#ifndef DEF_BUTTON
#define DEF_BUTTON

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include "Element.h"

class Button : public Element
{
	public:
        Button(std::string t, int w, int h, TTF_Font *ttf);
        ~Button();
        void mouseEnter();
        void mouseExit();
        void mouseClicked();
        void mousePressed();
        void mouseReleased();
        void print(int x, int y);


	private:
		std::string text;
        TTF_Font *font;
};

#endif
