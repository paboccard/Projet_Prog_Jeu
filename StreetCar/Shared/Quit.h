#ifndef QUIT_H
#define QUIT_H

#include "Pack.h"
#include <iostream>
#include <fstream>

class Quit : public Pack{
    
 public:
    
    Quit();
    
    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, Quit &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, Quit &t){
	t.read(f);
	return f;
    };

};

#endif
