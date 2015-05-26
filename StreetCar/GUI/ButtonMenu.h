#ifndef DEF_BUTTONMENU
#define DEF_BUTTONMENU

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include "Element.h"
#include "Label.h"
#include "Image.h"

class ButtonMenu : public Element
{
	public:
        ButtonMenu(SDL_Renderer *rend, std::string t, int w, int h, TTF_Font *ttf);
        ~ButtonMenu();
        void mouseEnter();
        void mouseExit();
        void mouseClicked();
        void mousePressed();
        void mouseReleased();

	private:
	std::string text;
        TTF_Font *font;
	SDL_Color color;
	Label* labelElem;
	Image* imageTrain;
};

#endif
