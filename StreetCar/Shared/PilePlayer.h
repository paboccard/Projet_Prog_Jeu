#ifndef PILEPLAYER_H
#define PILEPLAYER_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h" 
#include <iostream>
#include <fstream>

class PilePlayer : public Pack{

 public:

    int idPlayer;
    Tile hand[5];

    PilePlayer();
    PilePlayer(int idP, Tile myHand[5]);

    void print(std::ostream& f);
    void read(std::istream& f);
};

#endif
