#include "Square.h"
#include "Utils.h"

using namespace std;

Square::Square(idTile t, int x, int y) {
	coordinates.x = x ;
	coordinates.y = y ;
	type = t;
}

Square::~Square()
{

}

bool Square::isEmpty(){
	return getType() == Empty;
}

bool Square::isStation(){
	return type >= StationA && type <= StationM;
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

Square &Square::operator = (const Square &s)
{
	coordinates = s.coordinates;
	type  = s.type;
	return *this;
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

void Square::setCoordinates(int x, int y){
	coordinates.x = x;
	coordinates.y = y;
}

void Square::serialize(ostream &f) {
	f << type << " " << coordinates << " ";
}

void Square::deserialize(istream &f) {
    int t;
    f >> t;
    type = (idTile)t;
    f >> coordinates;
}

ostream& operator << (ostream &f, Square &s){
	s.serialize(f);
	return f;
}
istream& operator >> (istream &f, Square &s){
	s.deserialize(f);
    return f;
}
