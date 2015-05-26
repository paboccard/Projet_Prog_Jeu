#include "Context.h"

using namespace std;

Context::Context() {

}

void Context::addElement(Element* e) {
	elements.push_back(e);
}
