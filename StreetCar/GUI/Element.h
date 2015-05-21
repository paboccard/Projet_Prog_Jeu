#ifndef DEF_ELEMENT
#define DEF_ELEMENT

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <pthread.h>

class Element {
	public:
		Element(SDL_Surface *s = NULL, bool dde = false);
		~Element();
		virtual void print(SDL_Renderer *rend, int x, int y) = 0;
		void setPosition(int x, int y);
		bool isIn(int x, int y);
		virtual SDL_Texture* getTexture() = 0;

	protected:
		bool dragDropEnable;
		bool mouseHover;
		SDL_Rect rect;
		SDL_Surface *surface;
		
		pthread_mutex_t mutexRect;
};


#endif



