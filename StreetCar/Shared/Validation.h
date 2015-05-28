#ifndef VALIDATION_H
#define VALIDATION_H

#include "Pack.h"
#include "Packs.h"
#include <iostream>
#include <fstream>

class Validation : public Pack{
    
 public:

error_pack error;
    
    Validation();
    Validation(error_pack e);

    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, Validation &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, Validation &t){
	t.read(f);
	return f;
    };
};

#endif
