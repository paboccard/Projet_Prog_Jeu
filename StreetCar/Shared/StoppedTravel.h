#ifndef STOPPEDTRAVEL_H
#define STOPPEDTRAVEL_H

#include "Pack.h"
#include <iostream>
#include <unistd.h>
#include "Utils.h"

class StoppedTravel : public Pack{

 public:
    int idPlayer;

    StoppedTravel(int idP);
    void writePack(int fd);
};

#endif
