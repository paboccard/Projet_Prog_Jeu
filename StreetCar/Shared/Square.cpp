#include "Square.h"
#include "Utils.h"

using namespace std;

Square::Square() {
	coordinates = (Point){0,0};
	type = Empty;
	access[0] = false;
	access[1] = false;
	access[2] = false;
	access[3] = false;
}

// ATTENTION: voir .h
Square::Square(idTile t) {
	coordinates = (Point){0,0};
	type = t;
	access[0] = false;
	access[1] = false;
	access[2] = false;
	access[3] = false;
}
Square::Square(idTile t, int x, int y) {
	coordinates = (Point){x,y};
	type = t;
	access[0] = false;
	access[1] = false;
	access[2] = false;
	access[3] = false;
}

bool Square::isEmpty(){
    cout << "realy empty ? " << (int) getType() << endl;
	return this->getType() == Empty;
}

bool Square::isStation(){
	return type > 11 && type < 24;
}

bool Square::isTerminus(){
	return type > 24 && type < 49;
}

bool Square::isWall(){
	return type == Wall;
}

bool Square::isTile(){
    return type <= 11;
}

idTile Square::getType()
{
    return type;
}
ostream& operator << (std::ostream &f, Square &s){

	f << "Coordinates: X: " << s.coordinates.x << " Y: " << s.coordinates.y << endl;
	f << "Type: " << s.type << endl;
	f << "Access NORTH: " << s.access[NORTH] << endl;
	f << "Access SOUTH: " << s.access[SOUTH] << endl;
	f << "Access EAST: " << s.access[EAST] << endl;
	f << "Access WEST: " << s.access[WEST] << endl;
	return f;
}
