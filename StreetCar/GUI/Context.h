#ifndef CONTEXT_H
#define CONTEXT_H

#include "Element.h"
#include <vector>

class Context {
	public:
		Context();

	private:
		std::vector<Element *> elements;

};

#endif
