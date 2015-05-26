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
    
    NewPlayerAdd(Profile pro, int idP);
    
    friend std::ostream& operator << (std::ostream &f, NewPlayerAdd &t);
    friend std::istream& operator >> (std::istream &f, NewPlayerAdd &t);
};

#endif
