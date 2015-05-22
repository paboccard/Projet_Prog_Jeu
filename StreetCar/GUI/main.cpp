#include <iostream>
#include <pthread.h>
#include <string>

#include "UtilsGui.h"
#include "event.h"
#include "graphics.h"

using namespace std;

int main(int argc, char* argv[])
{
    SDL_Window *window;
    SDL_Renderer *ren;
    TTF_Font *font;

	ImagesData images;
	Context currentContext;

    //initialize SDL, window, render and TTF
    if(!init(window, ren, font, "SEM.TTF", 5)){
		return 1;
    }

	//load images
    SDL_Texture *background = loadTexture("images/PanamaLimited.jpg", ren);
    if (background == NULL){
		cleanup(ren, window, font);
		SDL_Quit();
		return 1;
    }

    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    SDL_RenderClear(ren);

	/*
		Init images
	*/

    //waiting action

    ProdCons<ElementEvent> *prodCons = new ProdCons<ElementEvent>();
    ParamThreadEvent paramEvent = {&currentContext, prodCons};
    pthread_t threadEvent;

    if (pthread_create(&threadEvent, NULL, event, (void *)(&paramEvent)) == 0){
        bool end = false;

        while (!end) {
            ElementEvent e;
            e = prodCons->consume();
            if (e.elem == NULL)
                end = true;
        }
        pthread_join(threadEvent, NULL);
        cout << "End of event thread" << endl;
    }else
        cout << "ERROR impossible to create event thread" << endl;

    delete prodCons;


    SDL_DestroyTexture(background);

	cleanup(ren, window, font);
	SDL_Quit();

	return 0;
}
