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

    StartTravel();
    StartTravel(int nbrT, std::vector<Tile> tr);
    
    void print(std::ostream& f);
    void read(std::istream& f);

};

#endif
