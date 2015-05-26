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

    PilePlayer(int idP, Tile myHand[5]);
    
    friend std::ostream& operator << (std::ostream &f, PilePlayer &t);
    friend std::istream& operator >> (std::istream &f, PilePlayer &t);
};

#endif
