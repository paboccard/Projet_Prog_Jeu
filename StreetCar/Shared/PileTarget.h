#ifndef PILETARGET_H
#define PILETARGET_H
#include <stdlib.h>    
#include <time.h> 
#include "Utils.h"
#include "Card.h"

class PileTarget {
	
public:
    PileTarget();
    Card take();
	
private:
    Card target[12];
    bool taked[12];
};

#endif
