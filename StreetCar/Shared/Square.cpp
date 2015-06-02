#include "Square.h"
#include "Utils.h"

using namespace std;

Square::Square(idTile t, int x, int y) {
	coordinates = (Point){x,y};
	type = t;

}

Square::~Square()
{

}

bool Square::isEmpty(){
	return getType() == Empty;
}

bool Square::isStation(){
	return type >= StationA && type <= StationL;
}

bool Square::isTerminus(){
	return type >= Terminus1_1 && type <= Terminus6_4;
}

bool Square::isWall(){
	return type == Wall;
}

void Square::print()
{
	cout << "Coordinates: X: " << coordinates.x << " Y: " << coordinates.y << endl;
	cout << "Type: " << type << endl;
}

bool Square::isTile(){
	return type <= StraightRDoubleCurves;
}

idTile Square::getType()
{
	return type;
}

void Square::setType(idTile id)
{
	type = id;
}

Point Square::getCoordinates()
{
	return coordinates;
}

void Square::setCoordinates(Point p)
{
	coordinates = p;
}
ostream& operator << (std::ostream &f, Square &s){
	f << s.type << " " << s.coordinates;
	return f;
}
