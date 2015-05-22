#ifndef STOPTRAVEL_H
#define STOPTRAVEL_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h" 
#include <iostream>
#include <vector>
#include <fstream>

class StopTravel : public Pack{

 public:
    int idPlayer;

    StopTravel(int idP);

    friend std::ostream& operator << (std::ostream &f, StopTravel &t);
    friend std::istream& operator >> (std::istream &f, StopTravel &t);

};

#endif
