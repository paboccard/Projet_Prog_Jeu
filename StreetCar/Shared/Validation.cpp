#include "Validation.h"

using namespace std;

Validation::Validation() : Pack(VALIDATION){}

Validation::Validation(error_pack e) : Pack(VALIDATION){
    error = e;
}

void Validation::print(ostream &f){
    Pack::print(f);
    f << error;
}

void Validation::read(istream &f){
    int e;
    f >> e;
    switch (e){
    case 0:
	error = IMPOSSIBLE_PLAY;
	break;
    case 1:
	error = TOO_MANY_TILES;
	break;
    case 2:
	error = WRONG_WAY;
	break;
    case 3:
	error = TILE_NOT_IN_HAND;
	break;
    }
}
