#include "guiThread.h"
#include "UtilsGui.h"
#include "graphics.h"
#include "paramThread.h"

void *guiThreadHandler(void *argv) {
	ParamGuiThread *param = (ParamGuiThread*)argv;

	// Data share by all thread
	ProdCons<ElementEvent> *prodConsEvent = param->prodConsEvent;
	Context *currentContext = param->context;

	cout << "Gui thread started successful" << endl;

    SDL_Window *window;
    SDL_Renderer *ren;
    TTF_Font *font;

	ImagesData images;

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
		return NULL;
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

	bool end = false;

	while (!end) {
		ElementEvent e;
		e = prodConsEvent->consume();
		if (e.elem == NULL)
			end = true;
	}

	SDL_DestroyTexture(background);

	cleanup(ren, window, font);
    TTF_Quit();
	SDL_Quit();

	return NULL;
}
