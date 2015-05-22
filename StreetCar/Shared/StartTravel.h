#ifndef STARTTRAVEL_H
#define STARTTRAVEL_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h" 
#include <iostream>
#include <vector>
#include <fstream>

class StartTravel : public Pack{

public:
int idPlayer;
std::vector<Tile> travel;

StartTravel(int nbrT, std::vector<Tile> tr);
    
    friend std::ostream& operator << (std::ostream &f, StartTravel &t);
    friend std::istream& operator >> (std::istream &f, StartTravel &t);
};

#endif
