#include <unistd.h>
#include "consoleThread.h"
#include "UtilsGui.h"
#include "paramThread.h"
#include <iostream>

using namespace std;

void *consoleThreadHandler(void *argv) {
	ParamEventThread *param = (ParamEventThread*)argv;

	Context * context = param->context;
	ProdCons<ElementEvent> *prodConsGui = param->prodConsEventGui;
	ProdCons<EventG *> *prodConsMotor = param->prodConsEventMotor;

	bool end = false;
	while (!end) {
		string commande;
		cin >> commande;
		if (!commande.compare("exit")) {
			prodConsMotor->produce(new GuiEvent((ElementEvent){NULL, (Action)0}));
			end = true;
		}
		else {
			cout << commande << endl;
		}

	}

	return NULL;
}
