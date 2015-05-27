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
    virtual ~Pack() {};
    friend std::ostream& operator << (std::ostream &f, Pack &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, Pack &t){
	cout << "bonjour" << endl;
	t.read(f);
	cout << "hello" << endl;
	return f;
    };

    virtual void print(std::ostream& f) = 0;
    virtual void read(std::istream& f) = 0;
};

#endif
