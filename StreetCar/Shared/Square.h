#ifndef SQUARE_H
#define SQUARE_H
#include "Point.h"
#include "Utils.h"
#include <fstream>
#include <iostream>

using namespace std;

class Square : Point{
 public:
    Point coordinates;
    idTile type;

    Square();
	Square(int x, int y, idTile i);
    bool isEmpty();
    bool isTerminus();
    bool isStation();
    bool isWall();
    bool access [4];
	friend std::ostream& operator << (std::ostream &f, Square &s);
};

#endif
