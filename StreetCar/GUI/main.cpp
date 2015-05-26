#include <iostream>
#include <pthread.h>
#include <string>

#include "EventG.h"
#include "paramThread.h"
#include "guiThread.h"
#include "consoleThread.h"
#include "eventThread.h"
#include "UtilsGui.h"
#include "Context.h"
#include "../Shared/ProdCons.h"

using namespace std;

int main(int argc, char* argv[])
{
	Context currentContext;

    ProdCons<ElementEvent> *prodConsEventGui = new ProdCons<ElementEvent>();
    ProdCons<EventG *> *prodConsInput = new ProdCons<EventG *>();
    ProdCons<Pack *> *prodConsOutput = new ProdCons<Pack *>();
    ParamEventThread paramEvent = {&currentContext, prodConsEventGui, prodConsInput};
    ParamGuiThread paramGui = {&currentContext, prodConsEventGui};
    pthread_t eventThread;
    pthread_t guiThread;
//    pthread_t inputThread;
//    pthread_t outputThread;

    if (pthread_create(&guiThread, NULL, guiThreadConsoleHandler, (void *)(&paramGui)) == 0){
		if (pthread_create(&eventThread, NULL, consoleThreadHandler, (void *)(&paramEvent)) == 0){
			
			bool end = false;



			while (!end) {
				EventG *event = prodConsInput->consume();

				if (event->idEvent == Server) {
					Pack p = ((ServerEvent*)event)->pack;

				}
				else {
					ElementEvent e = ((GuiEvent*)event)->elementEvent;

					if (e.elem == NULL) {
						prodConsEventGui->produce({NULL, (Action)0});
						end = true;
					}

				}

				delete event;
			}

			pthread_join(eventThread, NULL);
			cout << "End of event thread" << endl;
		}else
			cout << "ERROR impossible to create event thread" << endl;

		pthread_join(guiThread, NULL);
		cout << "End of Gui thread" << endl;
    }
	else 
        cout << "ERROR impossible to create gui thread" << endl;



    delete prodConsEventGui;
    delete prodConsInput;
    delete prodConsOutput;



	return 0;
}
