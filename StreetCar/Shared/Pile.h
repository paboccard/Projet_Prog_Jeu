#ifndef PILE_H
#define PILE_H
#include <stdlib.h>    
#include <time.h> 
#include "Utils.h"
#include <fstream>
#include <iostream>

class Pile {
	
public:
    Pile();
    idTile take();
    bool isEmpty();
    void updatePile(idTile t);

    int types[12];
    int total;

    friend std::ostream& operator << (std::ostream &f, Pile &p);
    friend std::istream& operator >> (std::istream &f, Pile &p);
};

#endif
