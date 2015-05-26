#include <iostream>
#include <string>
#include <unistd.h>

#include "EventG.h"
#include "../Shared/ProdCons.h"
#include "eventThread.h"
#include "consoleThread.h"
#include "UtilsGui.h"
#include "paramThread.h"

using namespace std;

void *eventThreadHandler(void* argv) {

	ParamEventThread *param = (ParamEventThread*)argv;

	Context *context = param->context;
	ProdCons<ElementEvent> *prodConsGui = param->prodConsEventGui;
	ProdCons<EventG*> *prodConsMotor = param->prodConsEventMotor;
	cout << "Event thread started successful" << endl;

    //starting SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
		cout << "ERROR SDL_Init: " << SDL_GetError() << endl;
		return 0;
    }
	*param->ok = true;

	bool end = false;

	SDL_Event event;

	while (!end) {

		SDL_WaitEvent(&event);
		switch(event.type) 
		{
			case SDL_KEYDOWN:
				switch(event.key.keysym.scancode) 
				{
					case SDL_SCANCODE_ESCAPE:
						end = true;
						break;
				}
				break;
			case SDL_WINDOWEVENT:

				break;
			case SDL_QUIT:
				end = true;
				break;
		}

	}
		prodConsMotor->produce(new GuiEvent((ElementEvent){NULL, (Action)0}));
	return NULL;
}
