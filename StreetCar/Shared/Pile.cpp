#include "Pile.h"
#include "Utils.h"



Pile::Pile(){
	total = 126;
	types[Straight]= 36;
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
	
	updatePile((idTile)card);
	return (idTile)card;
}

bool Pile::isEmpty(){
	return total == 0;
}

void Pile::updatePile(idTile t){
	types[t]--;
	total--;
}

ostream& operator << (ostream &f, Pile &t){
    
    f << "Number of tile: " << t.total << endl;
	f << Straight << ". Straight: " << t.types[Straight] << endl;
	f << Curve << ". Curve: " << t.types[Curve] << endl;
	f << Curve << ". DoubleCurves: " << t.types[DoubleCurves] << endl;
	f << Intersect << ". Intersect: " << t.types[Intersect] << endl;
	f << VCurve << ". VCurve: " << t.types[VCurve] << endl;
	f << StraightLCurve << ". StraightLCurve: " << t.types[StraightLCurve] << endl;
	f << StraightRCurve << ". StraightRCurve: " << t.types[StraightRCurve] << endl;
	f << HStraightVCurve << ". HStraightVCurve: " << t.types[HStraightVCurve] << endl;
	f << VStraightVCurve << ". VStraightVCurve: " << t.types[VStraightVCurve] << endl;
	f << CrossCurves << ". CrossCurves: " << t.types[CrossCurves] << endl;
	f << StraightLDoubleCurves << ". StraightLDoubleCurves: " << t.types[StraightLDoubleCurves] << endl;
	f << StraightRDoubleCurves << ". StraightRDoubleCurves: " << t.types[StraightRDoubleCurves] << endl;
    return f;
}