#ifndef STARTTRAVEL_H
#define STARTTRAVEL_H

#include "Pack.h"
#include <iostream>
#include <unistd.h>
#include "Utils.h"

class StartTravel : public Pack{

 public:
    int idPlayer;
    int nbrTiles;
    Tile travel[];

    StartTravel(int idP, int nbrT, Tile t[]);
    void writePack(int fd);
};

#endif
