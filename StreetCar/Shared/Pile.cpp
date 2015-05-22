#include "Pile.h"
#include "Utils.h"

Pile::Pile(){
	total = 126;
	types[Straight]= 36;
	types[Straight] = Straight;
	types[Curve] = 30;
	types[DoubleCurves] = 6;
	types[Intersect] = 4;
	types[VCurve] = 10;
	types[StraightLCurve] = 10;
	types[StraightRCurve] = 10;
	types[HStraightVCurve] = 6;
	types[VStraightVCurve] = 6;
	types[CrossCurves] = 4;
	types[StraightLDoubleCurves] = 2;
	types[StraightRDoubleCurves] = 2;
}

idTile Pile::take(){
	
	srand (time(NULL));
	int alea = (rand() % total) + 1;
	
	int card = 0;
	while(alea > types[card]) {
		alea -= types[card]; 
		card++;
	}
	total--;
	return (idTile)card;
}

bool Pile::isEmpty(){
	return total == 0;
}