#ifndef STOP_H
#define STOP_H
#include "Tile.h"
#include "Square.h"

class Tile;

class Stop: public Square {
private:
    Tile *linked;
public:
    Stop(idTile t);
	bool isLinked();
};

#endif