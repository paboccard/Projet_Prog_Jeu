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
  vector<GoalPlayer> goalPlayer;
  
  InitGame();
  InitGame(vector<vector<Tile> > h, Pile p, int firstP, vector<GoalPlayer> goalP);

  void print(std::ostream& f);
  void read(std::istream& f);
  
};

#endif
 
