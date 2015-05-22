#include <iostream>
#include <pthread.h>
#include <string>

#include "UtilsGui.h"
#include "eventThread.h"
#include "graphics.h"

using namespace std;

int main(int argc, char* argv[])
{
    SDL_Window *window;
    SDL_Renderer *ren;
    TTF_Font *font;

	ImagesData images;
	Context currentContext;

    /* initialisation */

    //starting SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        logSDLError(std::cout, "SDL_Init");
    }

    //opening window
    window = SDL_CreateWindow("Streetcar",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,  SDL_WINDOW_SHOWN);
    if (window == NULL){
        logSDLError(std::cout, "SDL_CreateWindow");
        SDL_Quit();
    }

    //create renderer
    ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL){
        SDL_DestroyWindow(window);
        logSDLError(std::cout, "SDL_CreateRenderer");
        SDL_Quit();
    }

    //initialize ttf
    if (TTF_Init() != 0){
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(window);
        logTTFError(std::cout, "TTF_Init");
        SDL_Quit();
    }

    //Open the font
    font = TTF_OpenFont("SHIFTY.TTF", 50);
    if (font == NULL){
        cleanup(ren, window, font);
        logTTFError(std::cout, "TTF_OpenFont");
    }
    /* end initialisation */


    /* elements */

	//load images
    SDL_Texture *background = loadTexture("images/PanamaLimited.jpg", ren);
    if (background == NULL){
		cleanup(ren, window, font);
        SDL_Quit();
		return 1;
    }

    //clear render
    SDL_RenderClear(ren);

    // dimension render
    int width, height;

    //draw background image in render
    SDL_QueryTexture(background, NULL, NULL, &width, &height);
    renderTexture(background, ren, 0, 0);

    //SDL_Surface* texte = TTF_RenderText_Blended(font,"La Bibliothèque SDL_ttf est bien installée", couleurTexte);
   // Element textElem = new Element(ren, texte);
   // textElem.color = {0, 0, 0};
   // textElem.texture = SDL_CreateTextureFromSurface(ren, texte);
    //renderTexture(textElem.texture, ren, 0, 0);

    //test affiche texte
    SDL_Color couleurTexte = {0, 0, 0};
    SDL_Surface* texte = TTF_RenderText_Blended(font,"La Bibliothèque SDL_ttf est bien installée", couleurTexte);
    SDL_Texture * test = SDL_CreateTextureFromSurface(ren, texte);
    renderTexture(test, ren, 0, 0);

    //update render
    SDL_RenderPresent(ren);



	/*
		Init images
	*/

    //waiting action

    ProdCons<ElementEvent> *prodConsEvent = new ProdCons<ElementEvent>();
    ProdCons<Pack> *prodConsInput = new ProdCons<Pack>();
    ProdCons<Pack> *prodConsOutput = new ProdCons<Pack>();
    ParamEventThread paramEvent = {&currentContext, prodConsEvent, prodConsOutput};
    ParamGuiThread paramEvent = {&currentContext, prodConsInput};
    pthread_t eventThread;
    pthread_t guiThread;
    pthread_t inputThread;
    pthread_t outputThread;

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
    TTF_Quit();
	SDL_Quit();

	return 0;
}
