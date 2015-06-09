#ifndef LAUNCH_H
#define LAUNCH_H

#include "Pack.h"
#include <iostream>
#include <fstream>

class Launch : public Pack{
    
 public:

    int numGame;
    Launch();
    Launch(int numG);
    
    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, Launch &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, Launch &t){
	t.read(f);
	return f;
    };

};

#endif
