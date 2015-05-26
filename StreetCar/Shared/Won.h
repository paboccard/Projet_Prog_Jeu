#ifndef WON_H
#define WON_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h" 
#include <iostream>
#include <vector>
#include <fstream>

class Won : public Pack{

 public:
    int idPlayer;
    
    Won();
    Won(int idP);

    void print(std::ostream& f);
    void read(std::istream& f);

};

#endif
