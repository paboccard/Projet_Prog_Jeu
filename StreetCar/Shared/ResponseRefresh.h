#ifndef RESPONSEREFRESH_H
#define RESPONSEREFRESH_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h" 
#include <iostream>
#include <vector>
#include <fstream>

class ResponseRefresh : public Pack{

 public:
  std::vector<GameNetwork> gameNetwork;
  ResponseRefresh();
  ResponseRefresh(std::vector<GameNetwork> game);

    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, ResponseRefresh &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, ResponseRefresh &t){
	t.read(f);
	return f;
    };

};

#endif
