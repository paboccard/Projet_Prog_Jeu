#ifndef IWANTPLAY_H
#define IWANTPLAY_H

#include "Pack.h"
#include "Profile.h"
#include <iostream>
#include <fstream>

class IWantPlay : public Pack{
    
 public:
    
    Profile profile;

    IWantPlay();
    IWantPlay(Profile pro);

    void print(std::ostream& f);
    void read(std::istream& f);
};

#endif
