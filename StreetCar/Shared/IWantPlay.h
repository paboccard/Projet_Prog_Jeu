#ifndef IWANTPLAY_H
#define IWANTPLAY_H

#include "Pack.h"
#include "Profile.h"
#include <iostream>
#include <fstream>

class IWantPlay : public Pack{
    
 public:
    
    Profile profile;
    
    IWantPlay(Profile pro);
    
    friend std::ostream& operator << (std::ostream &f, IWantPlay &t);
    friend std::istream& operator >> (std::istream &f, IWantPlay &t);
};

#endif
