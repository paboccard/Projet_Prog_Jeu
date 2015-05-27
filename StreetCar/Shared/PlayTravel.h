#ifndef PLAYTRAVEL_H
#define PLAYTRAVEL_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h"
#include <iostream>
#include <vector>
#include <fstream>

class PlayTravel : public Pack{

 public:
    int idPlayer;
    std::vector<Tile> travel;

    PlayTravel();
    PlayTravel(int idP, std::vector<Tile> tr);

    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, PlayTravel &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, PlayTravel &t){
	t.read(f);
	return f;
    };

};

#endif
