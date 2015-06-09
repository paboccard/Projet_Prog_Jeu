#ifndef STARTGAMENETWORK_H
#define STARTGAMENETWORK_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h" 
#include <iostream>
#include <vector>
#include <fstream>

class StartGameNetwork : public Pack{

 public:

    int numGame;

    StartGameNetwork();
    StartGameNetwork(int numG);

    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, StartGameNetwork &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, StartGameNetwork &t){
	t.read(f);
	return f;
    };

};

#endif
