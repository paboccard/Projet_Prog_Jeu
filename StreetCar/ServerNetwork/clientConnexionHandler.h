#ifndef CLIENTCONNEXIONHANDLER_H
#define CLIENTCONNEXIONHANDLER_H

#include "../Shared/Pack.h"
#include <sstream>
#include "../Shared/ParamThreadClient.h"
#include "../Shared/Utils.h"
#include "../Shared/StartGameNetwork.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void *clientInputConnexionHandler(void* argv); 
void *clientOutputConnexionHandler(void* argv);
 
#endif
