#ifndef PARAMTHREAD_H
#define PARAMTHREAD_H

#include "UtilsGui.h"
#include "EventG.h"
#include "../Shared/ProdCons.h"
#include "Context.h"

class EventG;

typedef struct {
	Context* context;
	ProdCons<ElementEvent> *prodConsEventGui;
	ProdCons<EventG *> *prodConsEventMotor;
} ParamEventThread;

typedef struct {
	Context* context;
	ProdCons<ElementEvent> *prodConsEvent;
} ParamGuiThread;

#endif
