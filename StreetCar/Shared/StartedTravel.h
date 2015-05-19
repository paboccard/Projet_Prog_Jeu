#ifndef STARTEDTRAVEL_H
#define STARTEDTRAVEL_H

#include <Pack.h>
#include <iostream>
#include <unistd.h>
#include <Utils.h>

class StartedTravel : public Pack{

 public:
    int idPlayer;
    int nbrTiles;
    Tile travel[];

    StartedTravel(int idP, int nbrT, Tile t[]);
    void writePack(int fd);
};

#endif
