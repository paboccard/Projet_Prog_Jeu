#ifndef PLAYER_H
#define PLAYER_H
#include "Utils.h"
#include "Profile.h"
#include "Tile.h"
#include "Stop.h"
#include <fstream>


typedef struct {
    bool isInTerminus;
    Tile curTile,prevTile;
    Orientation origin;
}Travel;

std::ostream& operator << (std::ostream &f, Travel &t);
std::istream& operator >> (std::istream &f, Travel &t);

//class Tile;
class Player {

public:
    Player();
    int myIdPlayer;
    Profile profile;
    Tile hand[5];
    bool isTravelling;
    Travel travel;
    int line;
    std::vector<Stop> itinerary;
    bool handIsEmpty();
    void strokePossible(int strokePossible[320][4]);
    
};

#endif



