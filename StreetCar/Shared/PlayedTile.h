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
    std::vector<Tile> tiles;
    
    PlayedTile();
    PlayedTile(std::vector<Tile> tilesPlayed);

    void print(std::ostream& f);
    void read(std::istream& f);
};

#endif
 
