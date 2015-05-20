#ifndef PLAYER_H
#define PLAYER_H
#include "Utils.h"
#include "Profile.h"
#include "Tile.h"
#include "Stop.h"

//class Tile;

class Player {
 private:
    Profile profile;
    Tile hand[5];
    int line;
    std::vector<Stop> itinerary;
    bool travel;
public:
    Player();

};

#endif
