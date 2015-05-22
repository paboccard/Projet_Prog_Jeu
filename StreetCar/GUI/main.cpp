#include <iostream>
#include <pthread.h>
#include <string>

#include "UtilsGui.h"
#include "eventThread.h"
#include "guiThread.h"


using namespace std;

int main(int argc, char* argv[])
{
	Context currentContext;

    ProdCons<ElementEvent> *prodConsEvent = new ProdCons<ElementEvent>();
    ProdCons<Pack> *prodConsInput = new ProdCons<Pack>();
    ProdCons<Pack> *prodConsOutput = new ProdCons<Pack>();
    ParamEventThread paramEvent = {&currentContext, prodConsEvent, prodConsOutput};
    ParamGuiThread paramGui = {&currentContext, prodConsEvent};
    pthread_t eventThread;
    pthread_t guiThread;
//    pthread_t inputThread;
//    pthread_t outputThread;

    if (pthread_create(&guiThread, NULL, guiThreadHandler, (void *)(&paramGui)) == 0){
		if (pthread_create(&eventThread, NULL, eventThreadHandler, (void *)(&paramEvent)) == 0){
			

			pthread_join(eventThread, NULL);
			cout << "End of event thread" << endl;
		}else
			cout << "ERROR impossible to create event thread" << endl;

		pthread_join(guiThread, NULL);
		cout << "End of Gui thread" << endl;
    }
	else 
        cout << "ERROR impossible to create gui thread" << endl;



    delete prodConsEvent;
    delete prodConsInput;
    delete prodConsOutput;



	return 0;
}
