#ifndef NEWPLAYERADD_H
#define NEWPLAYERADD_H

#include "Profile.h"
#include "Pack.h"
#include <iostream>
#include <fstream>

class NewPlayerAdd : public Pack{
    
 public:
    
    Profile profile;
    int idPlayer;
    
    NewPlayerAdd();
    NewPlayerAdd(Profile pro, int idP);

    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, NewPlayerAdd &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, NewPlayerAdd &t){
	t.read(f);
	return f;
    };

};

#endif
