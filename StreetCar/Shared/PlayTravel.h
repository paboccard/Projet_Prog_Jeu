#ifndef PLAYTRAVEL_H
#define PLAYTRAVEL_H

#include "Pack.h"
#include <iostream>
#include <unistd.h>
#include "Utils.h"

class PlayTravel : public Pack{

 public:
    int idPlayer;
    int nbrTiles;
    Tile travel[];

    PlayTravel(int idP, int nbrT, Tile t[]);
    void writePack(int fd);
};

#endif
