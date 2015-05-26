#ifndef PLAYEDTRAVEL_H
#define PLAYEDTRAVEL_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <vector>

class PlayedTravel : public Pack{

 public:
  int idNextPlayer;
  Travel tram;
  
  PlayedTravel();
  PlayedTravel(int idNextP, Travel travelOfTram);

  void print(std::ostream& f);
  void read(std::istream& f);
};

#endif
