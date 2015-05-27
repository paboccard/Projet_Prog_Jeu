#ifndef STOPTRAVEL_H
#define STOPTRAVEL_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h" 
#include <iostream>
#include <vector>
#include <fstream>

class StopTravel : public Pack{

 public:
    int idPlayer;

    StopTravel();
    StopTravel(int idP);

    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, StopTravel &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, StopTravel &t){
	t.read(f);
	return f;
    };

};

#endif
