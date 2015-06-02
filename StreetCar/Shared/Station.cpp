#include "Station.h"


Station::Station(idTile t, int x, int y) : Square(t, x, y){
	linked = NULL;
}

Station::~Station()
{

}

bool Station::isLinked(){
	return linked != NULL;
}
bool Station::getAccess(Orientation o) {
	return IMPOSSIBLE;
}


bool Station::canChange(Square*s) {
	return false;
}

void Station::rotate(int r) {

}

void Station::print() {
	Square::print();
}
