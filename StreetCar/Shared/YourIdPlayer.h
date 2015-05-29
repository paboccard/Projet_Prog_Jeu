#ifndef YOURIDPLAYER_H
#define YOURIDPLAYER_H

#include "Pack.h"
#include <iostream>
#include <fstream>

class YourIdPlayer : public Pack{
    
 public:
    
    int idPlayer;
    
    YourIdPlayer();
    YourIdPlayer(int idP);

    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, YourIdPlayer &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, YourIdPlayer &t){
	t.read(f);
	return f;
    };
};

#endif
