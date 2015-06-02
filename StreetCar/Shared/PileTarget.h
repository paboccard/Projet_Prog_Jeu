#ifndef PILETARGET_H
#define PILETARGET_H
#include <stdlib.h>
#include <time.h>
#include "Utils.h"
#include "Card.h"

#define NBR_DIFFERENT_CARDS 12

class PileTarget {

public:
    PileTarget();
    Card take();

private:
    Card target[12];
    bool taken[12];
};

#endif
