#ifndef CONTEXT_H
#define CONTEXT_H

#include <iostream>
#include "Element.h"
#include <vector>

class Context {
	public:
	Context();
	void addElement(Element* e);

	private:
	std::vector<Element*> elements;

};

#endif
