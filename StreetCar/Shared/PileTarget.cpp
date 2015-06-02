#include "PileTarget.h"


PileTarget::PileTarget(){
    for (int i = 0; i < NBR_DIFFERENT_CARDS; i ++)
        taken[i] = false;
}

Card PileTarget::take(){

	srand (time(NULL));
	int alea;

    do {
        alea = rand() % NBR_DIFFERENT_CARDS;
    } while(taken[alea]);


	taken[alea] = true;

	return target[alea];

}
