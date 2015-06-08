#ifndef RESPONSEPLAYERREFRESH_H
#define RESPONSEPLAYERREFRESH_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h" 
#include <iostream>
#include <vector>
#include <fstream>
#include "Profile.h"

class ResponsePlayerRefresh : public Pack{

 public:
  std::vector<Profile> profiles;
  ResponsePlayerRefresh();
  ResponsePlayerRefresh(std::vector<Profile> p);

    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, ResponsePlayerRefresh &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, ResponsePlayerRefresh &t){
	t.read(f);
	return f;
    };

};

#endif
