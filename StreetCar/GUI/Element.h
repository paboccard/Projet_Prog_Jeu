#ifndef DEF_ELEMENT
#define DEF_ELEMENT

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Element {
	public:
		Element(SDL_Surface *s, bool dde = false) {};
		~Element();
		void print(SDL_Renderer rend, int x, int y);
		void setPosition(int x, int y);
		bool isIn(int x, int y);

	protected:
		bool dragDropEnable;
		bool mouseHover;
		SDL_Rect rect;
		SDL_Surface *surface;
		
		pthread_mutex_t mutexRect;
};

#endif
