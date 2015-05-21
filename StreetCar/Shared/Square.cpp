#include "Square.h"

<<<<<<< HEAD
Square::Square() {
	coordinates = {0,0};
	type = Empty;
}
=======
using namespace std;

Square::Square() {}
>>>>>>> d5879a5788535e591473394e6154f14f448a363d

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
