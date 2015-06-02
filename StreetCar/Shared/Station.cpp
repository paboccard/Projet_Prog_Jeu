#include "Station.h"
#include <QDebug>

Station::Station(idTile t, int x, int y) : Square(t, x, y){
	if (!isStation()) {
		qDebug() << "ERROR: Constructor Tile: Bad idTile " << t;
	}
	linked = false;
}

Station::~Station()
{

}

bool Station::isLinked(){
	return linked;
}

void Station::setOrientation(Orientation o)
{
	orientation = o;
}

Orientation Station::getOrientation()
{
	return orientation;
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
