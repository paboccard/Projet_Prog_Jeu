#ifndef PACK_H
#define PACK_H

#include "Packs.h"
#include <fstream>

class Pack{
 public:    
    packs idPack;
    
    Pack() {};
    virtual ~Pack() {};
    friend std::ostream& operator << (std::ostream &f, Pack &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, Pack &t){
	t.read(f);
	return f;
    };

    virtual void print(std::ostream& f) = 0;
    virtual void read(std::istream& f) = 0;
};

#endif
