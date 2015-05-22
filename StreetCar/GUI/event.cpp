#include <iostream>
#include <string>
#include <unistd.h>

#include "event.h"

using namespace std;

void *event(void* argv) {

	cout << "Event thread started successful" << endl;

	ParamThreadEvent param = *((ParamThreadEvent*)argv);

	Context *context = param.context;
	ProdCons<ElementEvent> *prodCons = param.prodCons;

	bool end = false;

	int i = 0;

	while (!end) {

		ElementEvent e = {NULL, (Action)0};
        sleep(5);
		prodCons->produce(e);
		i ++;


		if (i > 0)
		{
			end = true;
		}
	}
	return NULL;
}
