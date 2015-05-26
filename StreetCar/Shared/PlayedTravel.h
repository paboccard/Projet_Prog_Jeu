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
  
  PlayedTravel(int idNextP, Travel travelOfTram);
  friend std::ostream& operator << (std::ostream &f, PlayedTravel &t);
  friend std::istream& operator >> (std::istream &f, PlayedTravel &t);

};

#endif
