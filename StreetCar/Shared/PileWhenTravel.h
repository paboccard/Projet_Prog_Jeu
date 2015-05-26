#ifndef PILEPWHENTRAVEL_H
#define PILEPWHENTRAVEL_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h" 
#include <iostream>
#include <fstream>
#include <vector>

class PileWhenTravel : public Pack{

 public:

    std::vector<int> idPlayers;
    std::vector<int> idHands;

    PileWhenTravel();
    PileWhenTravel(std::vector<int> idP, std::vector<int> idH);

    void print(std::ostream& f);
    void read(std::istream& f);
};

#endif
