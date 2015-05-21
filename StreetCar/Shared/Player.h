#ifndef PLAYER_H
#define PLAYER_H
#include "Utils.h"
#include "Profile.h"
#include "Tile.h"
#include "Stop.h"


typedef struct {
    bool isInTerminus;
    Tile curTile,prevTile;
    Orientation origin;
}Travel;

//class Tile;
class Player {
 private:
    Profile profile;
public:
    Player();
    Tile hand[5];
    bool isTravelling;
    Travel travel;
    int line;
    std::vector<Stop> itinerary;

};

#endif
