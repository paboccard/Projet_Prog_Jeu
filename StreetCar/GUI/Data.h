#ifndef GRAPHICDATA_H
#define GRAPHICDATA_H

#include <SDL2/SDL.h>

public class GraphicData {
	public:
		GraphicData();
		~GraphicData();

	private:
		SDL_Window *window;
		SDL_Render *renderWindow;
	
};

#endif
