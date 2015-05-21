#ifndef UTILSGUI_H
#define UTILSGUI_H

#include "../Shared/ProdCond.h"
#include "Data.h"
#include <string>

typedef struct {
	GraphicData *data;
	ProdCond<std::string> *prodCond;
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

#endif
