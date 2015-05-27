#ifndef STARTTRAVEL_H
#define STARTTRAVEL_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h" 
#include <iostream>
#include <vector>
#include <fstream>

class StartTravel : public Pack{

 public:
    int idPlayer;
    std::vector<Tile> travel;

    StartTravel();
    StartTravel(int nbrT, std::vector<Tile> tr);
    
    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, StartTravel &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, StartTravel &t){
	t.read(f);
	return f;
    };

};

#endif
