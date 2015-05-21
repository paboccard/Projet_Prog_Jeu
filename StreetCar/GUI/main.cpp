#include <iostream>
#include <pthread.h>
#include <string>

#include "UtilsGui.h"
#include "event.h"
#include "graphics.h"

using namespace std;

int main(int argc, char* argv[])
{
	GraphicData *data = new GraphicData();

    SDL_Window *window;
    SDL_Renderer *ren;
    TTF_Font *font;

    //initialize SDL, window, render and TTF
    if(init(window, ren, font)){
        //load images
        SDL_Texture *background = loadTexture("Images/PanamaLimited.jpg", ren);
        if (background == nullptr){
            cleanup(background, ren, window);
            SDL_Quit();
            return 1;
        }

    }



    //waiting action

    ProdCond<string> *prodCond = new ProdCond<string>();
    ParamThreadEvent paramEvent = {data, prodCond};
    pthread_t threadEvent;

    if (pthread_create(&threadEvent, NULL, event, (void *)(&paramEvent)) == 0){
        bool end = false;

        while (!end) {
            string s;
            s = prodCond->consume();
            cout << s << endl;
            if (s.compare("Kill") == 0)
                end = true;
        }
        pthread_join(threadEvent, NULL);
        cout << "End of event thread" << endl;
    }else
        cout << "ERROR impossible to create event thread" << endl;

    delete prodCond;
	delete data;

	return 0;
}
