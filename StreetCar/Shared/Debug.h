#ifndef DEBUG_H
#define DEBUG_H

#include "Pack.h"
#include <iostream>
#include <fstream>
#include <string>

//class Pack;

class Debug : public Pack{

 public:

    std::string debug;
    
    Debug();
    Debug(std::string deb);
    
    void print(std::ostream& f);
    void read(std::istream& f);
    
    friend std::ostream& operator << (std::ostream &f, Debug &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, Debug &t){
	t.read(f);
	return f;
    };
};

#endif
