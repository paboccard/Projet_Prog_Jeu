#ifndef PLAYTILE_H
#define PLAYTILE_H

#include "Pack.h"
#include <iostream>
#include <unistd.h>
#include "Utils.h"

class PlayTile : public Pack{

 public:
    int idPlayer;
    Stroke strokePlayed[2];

    PlayTravel(int idP, Stroke s[2]);
    void writePack(int fd);
};

#endif
