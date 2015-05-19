#ifndef DEF_ELEMENT
#define DEF_ELEMENT

#include <SDL2/SDL.h>

class Element {
	public:
		Element() {};
		void slot();
		virtual SDL_Rect *getRect() = 0;
		virtual void clicked() = 0;
		virtual void mouseEnter() = 0;

	protected:
		SDL_Rect *rect;	
}
