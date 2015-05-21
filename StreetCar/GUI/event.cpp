#include <iostream>
#include <string>
#include <unistd.h>

#include "event.h"

using namespace std;

void *event(void* argv) {

	cout << "Event thread tarted successful" << endl;

	ParamThreadEvent param = *((ParamThreadEvent*)argv);

	GraphicData *data = param.data;
	ProdCons<string> *prodCons = param.prodCons;

	bool end = false;

	int i = 0;

	while (!end) {
		string s;
		s = i;
		s += "coucou";
		prodCons->produce(s);
		i ++;
		sleep(1);

		if (i > 5)
		{
			prodCons->produce("Kill");
			end = true;
		}
	}
	return NULL;
}
