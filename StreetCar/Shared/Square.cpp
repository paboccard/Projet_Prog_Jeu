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

/*Only for the test*/
Square::Square(int x, int y, idTile i){
	coordinates = (Point){x,y};
	type = i;
	access[0] = false;
	access[1] = false;
	access[2] = false;
	access[3] = false;
}

bool Square::isEmpty(){
	return type == Empty;
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

ostream& operator << (std::ostream &f, Square &s){
	
	f << "Coordinates: X: " << s.coordinates.x << " Y: " << s.coordinates.y << endl;
	f << "Type: " << s.type << endl;
	return f;
}
