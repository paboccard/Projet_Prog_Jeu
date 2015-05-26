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

    StopTravel();
    StopTravel(int idP);

    void print(std::ostream& f);
    void read(std::istream& f);

};

#endif
