#ifndef PLAYTILE_H
#define PLAYTILE_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h"
#include <iostream>
#include <vector>
#include <fstream>

class PlayTile : public Pack{

 public:

    int idPlayer;
    Tile tiles[2];
    int idxHand[2];

    PlayTile(int idP, Tile myHand[5], int idTilePlay[2]);

    friend std::ostream& operator << (std::ostream &f, PlayTile &t);
    friend std::istream& operator >> (std::istream &f, PlayTile &t);
};

#endif
