#ifndef WON_H
#define WON_H

#include <Pack.h>
#include <iostream>
#include <unistd.h>
#include <Utils.h>

class Won : public Pack{

 public:
    int idPlayer;

    Won(int idP);
    void writePack(int fd);
};

#endif
