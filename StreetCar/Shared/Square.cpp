#include "Square.h"
#include "Utils.h"

using namespace std;

Square::Square() {
	coordinates = {0,0};
	type = Empty;
}

bool Square::isEmpty(){
	return type == Empty;
}

bool Square::isStation(){
	return type > 11 && type < 20;
}

bool Square::isTerminus(){
	return false;
}

bool Square::isWall(){
	return type == Wall;
}
