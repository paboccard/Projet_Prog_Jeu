#ifndef CREATEGAME_H
#define CREATEGAME_H

#include "Profile.h"
#include "Pack.h"
#include <iostream>
#include <fstream>

class CreateGame : public Pack{
    
 public:
    
    int nbrPlayer;
    
    CreateGame();
    CreateGame(int nbrP);

    void print(std::ostream& f);
    void read(std::istream& f);
};

#endif
