#include "Data.h"

using namespace std;

GraphicData::GraphicData() {

}

GraphicData::~GraphicData() {
//	SDL_DestroyRenderer(renderWindow);
//	SDL_DestroyWindow(window);
}

bool GraphicData::init() {
/*	SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP, &win, &rendWin);
	
	if (win == NULL || rendWin == NULL)
	{
		cout << "Create window and render ERROR in graphicData : " << SDL_GetError() << endl;
		return false;
	}
*/
	return true;
}
