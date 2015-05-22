#include "guiThread.h"
#include "UtilsGui.h"

void *guiThread(void *argv) {
	ParamGuiThread *param = (ParamGuiThread*)argv;

	// Data share by all thread
	ProdCons<ElementEvent> *prodCondEvent = param->prodConsEvent;
	Context *currentContext = param->context;


	return NULL;
}
