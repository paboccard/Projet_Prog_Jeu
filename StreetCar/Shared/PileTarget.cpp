#include "PileTarget.h"


PileTarget::PileTarget(){}

Card PileTarget::take(){
	
	srand (time(NULL));
	int alea = rand() % 12;
	
	while(taked[alea]) alea = rand() % 12;
	
	taked[alea] = false;
	
	return target[alea];
	
}