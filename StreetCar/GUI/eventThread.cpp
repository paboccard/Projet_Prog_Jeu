#include <iostream>
#include <string>
#include <unistd.h>

#include "eventThread.h"
#include "../Shared/ProdCons.h"
#include "UtilsGui.h"
#include "EventG.h"
#include "paramThread.h"

using namespace std;

void *eventThreadHandler(void* argv) {

	ParamEventThread *param = (ParamEventThread*)argv;

	Context *context = param->context;
	ProdCons<ElementEvent> *prodConsEvent = param->prodConsEventGui;
	ProdCons<EventG*> *prodConsServ = param->prodConsEventMotor;

	cout << "Event thread started successful" << endl;

	bool end = false;

	int i = 0;

	while (!end) {

		ElementEvent e = {NULL, (Action)0};
        sleep(5);
		prodConsEvent->produce(e);
		i ++;

		if (i > 0)
		{
			end = true;
		}
	}
	return NULL;
}
