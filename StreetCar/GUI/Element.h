#ifndef DEF_ELEMENT
#define DEF_ELEMENT

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <pthread.h>
#include <string>

class Element {
	public:
		Element(SDL_Renderer *r, SDL_Surface *s = NULL, bool dde = false);
		~Element();
		virtual void print(int x, int y);
		void setPosition(int x, int y);
		bool isIn(int x, int y);
		SDL_Surface *getSurface();
        SDL_Rect* getRect();


	protected:
		bool dragDropEnable;
		bool mouseHover;
        bool listenEvent;
		SDL_Rect rect;
		SDL_Surface *surface;
		SDL_Texture *texture;
		SDL_Renderer *ren;
		
		pthread_mutex_t mutexRect;
};

#endif
