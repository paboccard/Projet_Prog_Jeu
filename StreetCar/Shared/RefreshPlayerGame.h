#ifndef REFRESHPLAYERGAME_H
#define REFRESHPLAYERGAME_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h" 
#include "Profile.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "ProdCons.h"

class RefreshPlayerGame : public Pack{

 public:
    std::vector<Profile> players;
    RefreshPlayerGame(std::vector<Profile> p);

    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, RefreshPlayerGame &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, RefreshPlayerGame &t){
	t.read(f);
	return f;
    };

};

#endif
