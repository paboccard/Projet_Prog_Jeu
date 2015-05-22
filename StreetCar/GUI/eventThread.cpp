#include <iostream>
#include <string>
#include <unistd.h>

#include "eventThread.h"
#include "../Shared/ProdCons.h"
#include "UtilsGui.h"

using namespace std;

void *eventThread(void* argv) {

	cout << "Event thread started successful" << endl;

	ParamEventThread *param = (ParamEventThread*)argv;

	Context *context = param->context;
	ProdCons<ElementEvent> *prodConsEvent = param->prodConsEvent;
	ProdCons<Pack> *prodConsServ = param->prodConsServ;

	bool end = false;

	int i = 0;

	while (!end) {

		ElementEvent e = {NULL, (Action)0};
		prodConsEvent->produce(e);
		i ++;
		sleep(1);

		if (i > 0)
		{
			end = true;
		}
	}
	return NULL;
}
