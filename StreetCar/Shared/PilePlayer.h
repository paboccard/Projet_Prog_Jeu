#ifndef PILEPLAYER_H
#define PILEPLAYER_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h" 
#include <iostream>
#include <fstream>

class PilePlayer : public Pack{

 public:
    PilePlayer();
	PilePlayer(int idP, int idNextP, std::vector<Tile*> tilesPiled, std::vector<int> idxTile);
	~PilePlayer();

    int idPlayer;
    int idNextPlayer;
	std::vector<Tile*> tilesPiled;
    std::vector<int> idxTiles;

    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, PilePlayer &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, PilePlayer &t){
	t.read(f);
	return f;
    };

};

#endif
