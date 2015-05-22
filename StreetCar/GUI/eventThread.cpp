#include <iostream>
#include <string>
#include <unistd.h>

#include "eventThread.h"
#include "../Shared/ProdCons.h"
#include "UtilsGui.h"

using namespace std;

void *eventThreadHandler(void* argv) {

	ParamEventThread *param = (ParamEventThread*)argv;

	Context *context = param->context;
	ProdCons<ElementEvent> *prodConsEvent = param->prodConsEvent;
	ProdCons<Pack> *prodConsServ = param->prodConsServ;

	cout << "Event thread started successful" << endl;

	bool end = false;

	int i = 0;

	while (!end) {

		ElementEvent e = {NULL, (Action)0};
		sleep(3);
		prodConsEvent->produce(e);
		i ++;

		if (i > 0)
		{
			end = true;
		}
	}
	return NULL;
}
