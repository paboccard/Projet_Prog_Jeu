#ifndef STARTEDTRAVEL_H
#define STARTEDTRAVEL_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h"
#include "Utils.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <vector>


class StartedTravel : public Pack{

 public:
    int idPlayer;
    Travel tram;
    
    StartedTravel(int idP, Travel travelOfTram);
    friend std::ostream& operator << (std::ostream &f, StartedTravel &t);
    friend std::istream& operator >> (std::istream &f, StartedTravel &t);
};

#endif
