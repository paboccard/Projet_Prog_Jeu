#ifndef UTILSGUI_H
#define UTILSGUI_H

#include "../Shared/ProdCons.h"
#include "Data.h"
#include <string>

typedef struct {
	GraphicData *data;
	ProdCons<std::string> *prodCons;
} ParamThreadEvent;

enum Action {
	mouseEnter,
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

#endif
