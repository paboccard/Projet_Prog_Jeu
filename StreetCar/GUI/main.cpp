#include <iostream>
#include <pthread.h>
#include <string>
#include <unistd.h>

#include "EventG.h"
#include "eventThread.h"
#include "paramThread.h"
#include "guiThread.h"
#include "UtilsGui.h"
#include "Context.h"
#include "../Shared/ProdCons.h"

using namespace std;

void * eventThreadHandler(void*);

int main(int argc, char* argv[])
{
	Context currentContext;
	bool ok = false;

    ProdCons<ElementEvent> *prodConsEventGui = new ProdCons<ElementEvent>();
    ProdCons<EventG *> *prodConsInput = new ProdCons<EventG *>();
    ProdCons<Pack *> *prodConsOutput = new ProdCons<Pack *>();
    ParamEventThread paramEvent = {&currentContext, prodConsEventGui, prodConsInput, &ok};
    ParamGuiThread paramGui = {&currentContext, prodConsEventGui, &ok};
    pthread_t eventThread;
    pthread_t guiThread;
//    pthread_t inputThread;
//    pthread_t outputThread;

	if (pthread_create(&eventThread, NULL, eventThreadHandler, (void *)(&paramEvent)) == 0){
		if (pthread_create(&guiThread, NULL, guiThreadHandler, (void *)(&paramGui)) == 0){
			
			bool end = false;



			while (!end) {
				EventG *event = prodConsInput->consume();	//wait event

				if (event->idEvent == Server) { //event from server
					Pack p = ((ServerEvent*)event)->pack;

				}
				else {	//event from SDL
					ElementEvent e = ((GuiEvent*)event)->elementEvent;

					if (e.elem == NULL) {
						prodConsEventGui->produce({NULL, (Action)0});
						end = true;
					}

				}

				delete event;
			}
			pthread_join(guiThread, NULL);
			cout << "End of Gui thread" << endl;
		}
		else 
			cout << "ERROR impossible to create gui thread" << endl;

		pthread_join(eventThread, NULL);
		cout << "End of event thread" << endl;
	}else
		cout << "ERROR impossible to create event thread" << endl;




    delete prodConsEventGui;
    delete prodConsInput;
    delete prodConsOutput;



	return 0;
}
