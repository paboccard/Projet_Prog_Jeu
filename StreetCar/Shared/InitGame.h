#ifndef INITGAME_H
#define INITGAME_H

#include "Pack.h"
#include "Packs.h"
#include "Utils.h"
#include "Tile.h" 
#include "Pile.h" 
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class InitGame : public Pack{
  
 public:
  vector<vector<Tile> > hands;
  Pile pile;
  int idFirstPlayer;
  GoalPlayer goalPlayer;
  
  InitGame();
  InitGame(vector<vector<Tile> > h, Pile p, int firstP, GoalPlayer goalP);

  void print(std::ostream& f);
  void read(std::istream& f);

  friend std::ostream& operator << (std::ostream &f, InitGame &t){
    t.print(f);
    return f;
  };
  friend std::istream& operator >> (std::istream &f, InitGame &t){
    t.read(f);
    return f;
  };
  
};

#endif
 
