#ifndef UTILSGUI_H
#define UTILSGUI_H

#include <string>
#include <vector>
#include "../Shared/ProdCons.h"
#include "Element.h"
#include "Context.h"
#include "../Shared/Pack.h"

enum Action {
	mouseEnter = 0,
	mouseExit,
	mouseClicked,
	mousePressed,
	mouseReleased,
	dragged,
	droped
};

typedef struct {
	Element* elem;
	Action action;
} ElementEvent;

typedef struct {
	Context* context;
	ProdCons<ElementEvent> *prodConsEvent;
	ProdCons<Pack> *prodConsServ;
} ParamEventThread;

typedef struct {
	Context* context;
	ProdCons<ElementEvent> *prodConsEvent;
} ParamGuiThread;

typedef struct {
	vector<Element*> tiles;
} ImagesData;

#endif
