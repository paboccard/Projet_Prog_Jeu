#include "Station.h"
#include <QDebug>

Station::Station(idTile t, int x, int y) : Square(t, x, y){
	if (!isStation()) {
		qDebug() << "ERROR: Constructor Tile: Bad idTile " << t;
	}
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
