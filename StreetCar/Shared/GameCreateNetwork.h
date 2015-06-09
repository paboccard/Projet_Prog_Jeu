#ifndef GAMECREATENETWORK_H
#define GAMECREATENETWORK_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h" 
#include <iostream>
#include <vector>
#include <fstream>

class GameCreateNetwork : public Pack{

 public:

    GameNetwork gameNetwork;
    GameCreateNetwork();
    GameCreateNetwork(GameNetwork g);

    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, GameCreateNetwork &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, GameCreateNetwork &t){
	t.read(f);
	return f;
    };

};

#endif
