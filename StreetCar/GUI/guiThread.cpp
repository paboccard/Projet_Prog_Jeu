#include "guiThread.h"
#include "UtilsGui.h"
#include "graphics.h"
#include "Label.h"
#include "ButtonMenu.h"
#include "SDL2/SDL_rect.h"

void *guiThreadHandler(void *argv) {
	ParamGuiThread *param = (ParamGuiThread*)argv;

	// Data share by all thread
	ProdCons<ElementEvent> *prodConsEvent = param->prodConsEvent;
	Context *currentContext = param->context;

	cout << "Gui thread started successful" << endl;

    SDL_Window *window;
    SDL_Renderer *ren;
    TTF_Font *fontTitle;
    TTF_Font *fontSubtitle;
    TTF_Font *fontText;
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

    //Open the font main title
    fontTitle = TTF_OpenFont("SHIFTY.TTF", 50);
    if (fontTitle == NULL){
        cleanup(ren, window, fontTitle);
        logTTFError(std::cout, "TTF_OpenFont_Title");
    }

    //Open the font sub title
    fontSubtitle = TTF_OpenFont("SHIFTY.TTF", 30);
    if (fontSubtitle == NULL){
        cleanup(ren, window, fontSubtitle);
        logTTFError(std::cout, "TTF_OpenFont_Subtitle");
    }

    //Open the font sub title
    fontText = TTF_OpenFont("SHIFTY.TTF", 20);
    if (fontText == NULL){
        cleanup(ren, window, fontText);
        logTTFError(std::cout, "TTF_OpenFont_Text");
    }

    /* end initialisation */


    /* elements */
    
    /* background context */
    SDL_Texture *background = loadTexture("images/PanamaLimited.jpg", ren);
    if (background == NULL){
	cleanup(ren, window, fontText);
        SDL_Quit();
	return NULL;
    }

    /* title context */
    Label* labelTitle = new Label(ren, "Streetcar", 100, 50, fontTitle, {0,0,0});


   /* background menu */
   SDL_Surface* surfaceMenu = SDL_CreateRGBSurface(0, SCREEN_WIDTH/2, SCREEN_HEIGHT-120, 32, 0, 0, 0, 0);
   Element* backgroundMenu = new Element(ren, surfaceMenu);

    /* main menu */
    ButtonMenu* buttonContinue = new ButtonMenu(ren, "Continuer une partie", 300, 50, fontSubtitle);
    ButtonMenu* buttonNGL = new ButtonMenu(ren, "Nouveau Jeu en local", 300, 50, fontSubtitle);
    ButtonMenu* buttonNGN = new ButtonMenu(ren, "Nouveau Jeu en Reseau", 300, 50, fontSubtitle);
    ButtonMenu* buttonLG = new ButtonMenu(ren, "Charger une partie", 100, 50, fontText);
    ButtonMenu* buttonTuto = new ButtonMenu(ren, "Tutoriel", 100, 50, fontText);
    ButtonMenu* buttonProfile = new ButtonMenu(ren, "Profil", 100, 50, fontText);
    ButtonMenu* buttonOptions = new ButtonMenu(ren, "Options", 100, 50, fontText);
    ButtonMenu* buttonExit = new ButtonMenu(ren, "Quitter le Jeu", 100, 50, fontText);

   

    //clear render
    SDL_RenderClear(ren);

    //draw elements
    renderTexture(background, ren, 0, 0);
    labelTitle->print((SCREEN_WIDTH/2)-50, 20);
    backgroundMenu->print(10,100);

    buttonContinue->print(40,120);
    buttonNGL->print(40,180);
    //buttonNGN->print(40,220);
    /*buttonLG->print(20,180);
    buttonTuto->print(20,100);
    buttonProfile->print(20,120);
    buttonOptions->print(20,140);
    buttonExit->print(20,160);*/











    //test affiche texte
    //SDL_Texture * test = renderText("toto", "SHIFTY.TTF", {255, 0, 0}, 40, ren);
    //renderTexture(test, ren, 0, 0);

  
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

	cleanup(ren, window, fontText);
    TTF_Quit();
	SDL_Quit();

	return NULL;
}
