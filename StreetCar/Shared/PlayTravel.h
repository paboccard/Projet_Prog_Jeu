#ifndef PLAYTRAVEL_H
#define PLAYTRAVEL_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h"
#include <iostream>
#include <vector>
#include <fstream>

class PlayTravel : public Pack{

 public:
    int idPlayer;
    std::vector<Tile> travel;

    PlayTravel(int idP, std::vector<Tile> tr);
    
    friend std::ostream& operator << (std::ostream &f, PlayTravel &t);
    friend std::istream& operator >> (std::istream &f, PlayTravel &t);
};

#endif
