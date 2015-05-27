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

    friend std::ostream& operator << (std::ostream &f, IWantPlay &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, IWantPlay &t){
	t.read(f);
	return f;
    };

};

#endif
