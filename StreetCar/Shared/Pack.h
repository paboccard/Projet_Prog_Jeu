#ifndef PACK_H
#define PACK_H

#include "Packs.h"
#include <fstream>
#include <iostream>

using namespace std;

class Pack{
 public:    
    packs idPack;
    
    Pack() {};
    
    Pack(packs idP) {
	idPack = idP;
    };
    virtual ~Pack() {};
    
    friend std::ostream& operator << (std::ostream &f, Pack &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, Pack &t){
	t.read(f);
	return f;
    };

    virtual void print(std::ostream& f){
	f << idPack;
    };
    virtual void read(std::istream& f){
	f >> idPack;
    };
};

#endif
