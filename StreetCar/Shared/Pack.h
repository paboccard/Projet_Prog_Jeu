#ifndef PACK_H
#define PACK_H

#include "Packs.h"
#include <fstream>

class Pack{
 public:    
    packs idPack;
    
    Pack() {};
    friend std::ostream& operator << (std::ostream &f, Pack &t);
    friend std::istream& operator >> (std::istream &f, Pack &t);
};

#endif
