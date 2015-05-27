#ifndef WON_H
#define WON_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h" 
#include <iostream>
#include <vector>
#include <fstream>

class Won : public Pack{

 public:
    int idPlayer;
    
    Won();
    Won(int idP);

    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, Won &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, Won &t){
	t.read(f);
	return f;
    };

};

#endif
