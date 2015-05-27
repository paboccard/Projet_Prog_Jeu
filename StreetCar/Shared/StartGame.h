#ifndef STARTGAME_H
#define STARTGAME_H

#include "Pack.h"
#include <iostream>
#include <fstream>

class StartGame : public Pack{
    
 public:
    
    StartGame();
    
    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, StartGame &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, StartGame &t){
	t.read(f);
	return f;
    };

};

#endif
