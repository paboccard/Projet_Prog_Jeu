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

    PileWhenTravel(std::vector<int> idP, std::vector<int> idH);
    
    friend std::ostream& operator << (std::ostream &f, PileWhenTravel &t);
    friend std::istream& operator >> (std::istream &f, PileWhenTravel &t);
};

#endif
