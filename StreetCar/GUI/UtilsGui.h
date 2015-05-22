#ifndef UTILSGUI_H
#define UTILSGUI_H

#include "../Shared/ProdCons.h"
#include "Element.h"
#include "Context.h"
#include <string>
#include <vector>

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
	Element *elem;
	Action action;
} ElementEvent;

typedef struct {
	Context* context;
	ProdCons<ElementEvent> *prodCons;
} ParamThreadEvent;

typedef struct {
	vector<Element*> tiles;
} ImagesData;
#endif
