#ifndef PLAYER_H
#define PLAYER_H
#include "Utils.h"
#include "Profile.h"
#include "Tile.h"
#include "Station.h"
#include <set>
#include <fstream>


typedef struct {
    bool isInTerminus;
    Tile curTile,prevTile;
    Orientation origin;
}Travel;
 
bool operator<(Stroke const &s1, Stroke const &s2);
bool operator==(Stroke &s1, Stroke &s2);
std::ostream& operator << (std::ostream &f, Stroke &s);

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
    std::vector<Station> itinerary;
    bool handIsEmpty();

    set<Stroke> strokePossible();


    void strokePossible(int strokePossible[320][4]);
    

};

#endif



