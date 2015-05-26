#ifndef EVENT_H
#define EVENT_H

#include "../Shared/Pack.h"
#include "UtilsGui.h"

enum event {
	Server = 0,
	Gui
};

class EventG {
	public:
		event idEvent;
		EventG(event e = Server);
};

class ServerEvent : public EventG {
	public:
		Pack pack;
		ServerEvent(Pack p);
};

class GuiEvent : public EventG {
	public:
		ElementEvent elementEvent;
		GuiEvent(ElementEvent e);
};

#endif
