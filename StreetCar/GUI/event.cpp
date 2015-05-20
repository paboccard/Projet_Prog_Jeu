#include "UtilsGui.h"

void *event(void* argv) {

	ParamThreadEvent param = (ParamThreadEvent)argv;

	Data *data = param.data;
	ProdCond *prodCond = param.prodCond;

	bool end = false;

	int i = 0;

	while (!end) {
		
		prodCond.producte("Coucou " + i);
		i ++;
		delay(1);

		if (i > 5)
		{
			end = true;
		}
	}
	return NULL;
}
