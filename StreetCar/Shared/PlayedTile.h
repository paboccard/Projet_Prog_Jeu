#ifndef PLAYEDTILE_H
#define PLAYEDTILE_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <vector>

class PlayedTile : public Pack{
    
 public:
    int idNextPlayer;
    std::vector<Tile> tiles;
    
    PlayedTile(int idP, std::vector<Tile> tilesPlayed);
    friend std::ostream& operator << (std::ostream &f, PlayedTile &pt);
    friend std::istream& operator >> (std::istream &f, PlayedTile &pt);
 
};

#endif
 
