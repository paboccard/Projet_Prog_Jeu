#ifndef PLAYEDTILE_H
#define PLAYEDTILE_H

#include <Pack.h>
#include <iostream>
#include <unistd.h>
#include <Utils.h>

class PlayedTile : public Pack{

 public:
    int idNextPlayer;
    Stroke strokePlayed[2];

    PlayTravel(int idP, Stroke s[2]);
    void writePack(int fd);
};

#endif
