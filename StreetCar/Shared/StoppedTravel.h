#ifndef STOPPEDTRAVEL_H
#define STOPPEDTRAVEL_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h" 
#include <iostream>
#include <vector>
#include <fstream>

class StoppedTravel : public Pack{

 public:
    int idNextPlayer;

    StoppedTravel();
    StoppedTravel(int idNextP);

    void print(std::ostream& f);
    void read(std::istream& f);


};

#endif
