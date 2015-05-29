#ifndef CLIENTGUIHANDLER_H
#define CLIENTGUIHANDLER_H

#include "../Shared/Pack.h"
#include <sstream>

void *clientOutputHandler(void* argv);
void *clientInputHandler(void* argv);
//Pack* deserialize(Pack* p, std::stringstream s); 

#endif
