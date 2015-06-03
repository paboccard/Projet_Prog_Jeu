#include "Station.h"
#include <iostream>

using namespace std;

Station::Station(idTile t, int x, int y) : Square(t, x, y){
	if (!isStation()) {
		cout << "ERROR: Constructor Station: Bad idTile " << t << endl;
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

void Station::print() {
	Square::print();
}

void Station::change(Square *s)
{
	cout << "Error, can't change a station " << endl;
}


/*ostream& operator << (ostream &f, Station &t){
    f << linked << " ";
    f << orientation;
}
istream& operator >> (istream &f, Station &t){}*/
