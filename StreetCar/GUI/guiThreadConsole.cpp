#include "guiThread.h"
#include "paramThread.h"
#include <iostream>

using namespace std;

void *guiThreadConsoleHandler(void *argv) {
	ParamGuiThread *param = (ParamGuiThread*)argv;

	// Data share by all thread
	ProdCons<ElementEvent> *prodConsEvent = param->prodConsEvent;
	Context *currentContext = param->context;

	cout << "Gui thread started successful" << endl;

	bool end = false;

	while (!end) {
		ElementEvent event = prodConsEvent->consume();

		if (event.elem == NULL) {
			end = true;
		}
		else {

		}
	}

	return NULL;
}
