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

    PlayTravel();
    PlayTravel(int idP, std::vector<Tile> tr);

    void print(std::ostream& f);
    void read(std::istream& f);

};

#endif
