#include "Validation.h"

using namespace std;

Validation::Validation() : Pack(){}

Validation::Validation(error_pack e) : Pack(){
    idPack = VALIDATION;
    error = e;
}

void Validation::print(ostream &f){
    f << VALIDATION << " ";
    f << error;
}

void Validation::read(istream &f){
    int i;
    f >> i;
    idPack = VALIDATION;
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
