#ifndef PILEPWHENTRAVEL_H
#define PILEPWHENTRAVEL_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h" 
#include <iostream>
#include <fstream>
#include <vector>

class PileWhenTravel : public Pack{

 public:

    std::vector<int> idPlayers;
    std::vector<int> idHands;

    PileWhenTravel();
    PileWhenTravel(std::vector<int> idP, std::vector<int> idH);

    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, PileWhenTravel &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, PileWhenTravel &t){
	t.read(f);
	return f;
    };

};

#endif
