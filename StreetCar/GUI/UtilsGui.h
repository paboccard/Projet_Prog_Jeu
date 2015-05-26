#ifndef UTILSGUI_H
#define UTILSGUI_H

#include <string>
#include <vector>
#include "Element.h"

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
	std::vector<Element*> tiles;
} ImagesData;

#endif
