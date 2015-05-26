#include "EventG.h"

EventG::EventG(event e) {
	idEvent = e;
}

ServerEvent::ServerEvent(Pack p) : EventG(Server) {
	pack = p;
}

GuiEvent::GuiEvent(ElementEvent e) : EventG(Gui) {
	elementEvent = e;
}
