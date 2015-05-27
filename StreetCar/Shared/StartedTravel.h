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

    StartedTravel();
    StartedTravel(int idP, Travel travelOfTram);

    void print(std::ostream& f);
    void read(std::istream& f);

};

#endif
