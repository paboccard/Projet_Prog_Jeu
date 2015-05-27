#ifndef STOPPEDTRAVEL_H
#define STOPPEDTRAVEL_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h" 
#include <iostream>
#include <vector>
#include <fstream>

class StoppedTravel : public Pack{

 public:
    int idNextPlayer;

    StoppedTravel();
    StoppedTravel(int idNextP);

    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, StoppedTravel &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, StoppedTravel &t){
	t.read(f);
	return f;
    };

};

#endif
