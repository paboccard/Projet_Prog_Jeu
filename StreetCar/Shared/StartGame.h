#ifndef STARTGAME_H
#define STARTGAME_H

#include "Pack.h"
#include <iostream>
#include <fstream>

class StartGame : public Pack{
    
 public:
    
    StartGame();
    
    void print(std::ostream& f);
    void read(std::istream& f);
};

#endif
