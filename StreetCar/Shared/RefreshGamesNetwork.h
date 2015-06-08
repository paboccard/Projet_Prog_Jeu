#ifndef REFRESHGAMESNETWORK_H
#define REFRESHGAMESNETWORK_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h" 
#include <iostream>
#include <vector>
#include <fstream>
#include "ProdCons.h"

class RefreshGamesNetwork : public Pack{

 public:
  ProdCons<Pack*> *prodConsClient;
    RefreshGamesNetwork();

    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, RefreshGamesNetwork &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, RefreshGamesNetwork &t){
	t.read(f);
	return f;
    };

};

#endif
