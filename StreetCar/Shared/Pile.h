#ifndef PILE_H
#define PILE_H
#include <stdlib.h>    
#include <time.h> 
#include "Utils.h"
#include <fstream>
#include <iostream>

using namespace std;

class Pile {
	
public:
	Pile();
	idTile take();
	bool isEmpty();
	void updatePile(idTile t);
    friend std::ostream& operator << (std::ostream &f, Pile &t);
	
private:
    int types[12];
	int total;
};

#endif
