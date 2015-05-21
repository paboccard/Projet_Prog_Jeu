#ifndef PILE_H
#define PILE_H
#include <stdlib.h>    
#include <time.h> 
#include "Utils.h"

class Pile {
	
public:
	Pile();
	idTile take();
    int types[12];
	int total = 126;
};

#endif
