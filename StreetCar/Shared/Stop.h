#ifndef STOP_H
#define STOP_H
#include "Square.h"
#include "Tile.h"

class Stop: public Square {
private:
    Tile *linked;
public:
    Stop(idTile t);
    bool isLinked();
};

#endif
