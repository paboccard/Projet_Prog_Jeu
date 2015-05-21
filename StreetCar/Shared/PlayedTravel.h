#ifndef PLAYEDTRAVEL_H
#define PLAYEDTRAVEL_H

#include "Pack.h"
#include <iostream>
#include <unistd.h>
#include "Utils.h"

class PlayedTravel : public Pack{

 public:
    int idNextPlayer;
    int nbrTiles;
    Tile travel[];

    PlayedTravel(int idP, int nbrT, Tile t[]);
    void writePack(int fd);
};

#endif
