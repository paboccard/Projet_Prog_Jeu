#ifndef DEBUG_H
#define DEBUG_H

#include "Profile.h"
#include "Pack.h"
#include <iostream>
#include <fstream>
#include <string>

class Debug : public Pack{
    
 public:
    
    std::string debug;
    
    Debug();
    Debug(std::string deb);

    void print(std::ostream& f);
    void read(std::istream& f);
};

#endif
