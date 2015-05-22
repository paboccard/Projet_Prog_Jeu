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

    Won(int idP);

    friend std::ostream& operator << (std::ostream &f, Won &t);
    friend std::istream& operator >> (std::istream &f, Won &t);

};

#endif
