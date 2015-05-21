#include "Square.h"

Square::Square() {
	coordinates = {0,0};
	type = Empty;
}

bool Square::isEmpty(){
	return type == idTile.Empty;
}

bool Square::isStation(){
	return type > 11 && type < 20;
}

bool Square::isTerminus(){
	return type == idTile.isEmpty;
}

bool Square::isWall(){
	return type == idTile.Wall;
}