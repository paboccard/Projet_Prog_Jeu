#ifndef PLAYER_H
#define PLAYER_H
#include "Utils.h"
#include "Profile.h"
#include "Tile.h"
#include "Station.h"
#include "Card.h"
#include <set>
#include <fstream>


typedef struct {
    bool isInTerminus;
	Tile *curTile;
	Tile *prevTile;
    Orientation origin;
}Travel;

typedef struct{
  Card stop;
  int line;
}GoalPlayer;
 
bool operator<(Stroke const &s1, Stroke const &s2);
bool operator==(Stroke &s1, Stroke &s2);
std::ostream& operator << (std::ostream &f, Stroke &s);

std::ostream& operator << (std::ostream &f, Travel &t);
std::istream& operator >> (std::istream &f, Travel &t);

//class Tile;
class Player {

 public:
    Player();
    int getMyIdPlayer();
    Tile** getHand();
    int getLine();
    bool getTravelling();
    Profile getProfile();
    std::vector<Station*> getItinerary();
    void setMyIdPlayer(int i);
    void setHand(Tile *h[5]);
    void setLine(int l);
    void setTravelling(bool travelling);
    void setProfile(Profile p);
    void setItinerary(std::vector<Station*> it);
	bool handIsEmpty();

    std::set<Stroke> strokePossible();

 private:
    int myIdPlayer;
    Profile profile;
    Tile* hand[5];
    bool isTravelling;
    Travel travel;
    int line;
    std::vector<Station*> itinerary;


    //void strokePossible(int strokePossible[320][4]);


};

#endif



