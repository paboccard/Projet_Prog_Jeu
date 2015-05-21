#ifndef SQUARE_H
#define SQUARE_H
#include "Point.h"
#include "Utils.h"


class Square : Point{
 public:
    Point coordinates;
    idTile type;

    Square();
	bool isEmpty();
	bool isTerminus();
	bool isStation();
	bool isWall();
    bool access [4];
};

#endif
