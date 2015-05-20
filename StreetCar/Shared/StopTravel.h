#ifndef STOPTRAVEL_H
#define STOPTRAVEL_H

#include <Pack.h>
#include <iostream>
#include <unistd.h>
#include <Utils.h>

class StopTravel : public Pack{

 public:
    int idPlayer;

    StopTravel(int idP);
    void writePack(int fd);
};

#endif
