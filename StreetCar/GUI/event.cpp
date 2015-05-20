#include <iostream>
#include <string>
#include <unistd.h>

#include "event.h"

using namespace std;

void *event(void* argv) {

	cout << "Event thread tarted successful" << endl;

	ParamThreadEvent param = *((ParamThreadEvent*)argv);

	GraphicData *data = param.data;
	ProdCond<string> *prodCond = param.prodCond;

	bool end = false;

	int i = 0;

	while (!end) {
		
		prodCond->producte("Coucou " + i);
		i ++;
		sleep(1);

		if (i > 5)
		{
			prodCond->producte("Kill");
			end = true;
		}
	}
	return NULL;
}
