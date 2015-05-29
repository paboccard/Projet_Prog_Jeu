#ifndef SQUARE_H
#define SQUARE_H
#include "Point.h"
#include "Utils.h"
#include <fstream>
#include <iostream>

using namespace std;



enum Orientation {
    WEST=0,
    SOUTH,
    EAST,
    NORTH
};


class Square : Point{
 public:
    Point coordinates;
    idTile type;

    Square();
	
	// ATTENTION: NE JAMAIS UTILISER DIRECTEMENT, ACCESS NON MIS A JOUR
	// NE SERT QUE POUR TILE -- PROBLEME HERITAGE
	Square(idTile t);
	
	Square(int x, int y, idTile i);
    bool isEmpty();
    bool isTerminus();
    bool isStation();
    bool isTile();
    bool isWall();
    bool access [4];
	friend std::ostream& operator << (std::ostream &f, Square &s);
};

#endif
