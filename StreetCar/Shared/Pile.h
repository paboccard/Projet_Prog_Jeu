#ifndef PILE_H
#define PILE_H
#include <stdlib.h>    
#include <time.h> 
#include "Utils.h"

class Pile {
	
public:
	Pile();
	idTile take();
	bool isEmpty();
private:
    int types[12];
	int total;
};

#endif
