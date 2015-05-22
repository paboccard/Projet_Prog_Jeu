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

    StoppedTravel(int idNextP);

    friend std::ostream& operator << (std::ostream &f, StoppedTravel &t);
    friend std::istream& operator >> (std::istream &f, StoppedTravel &t);

};

#endif
