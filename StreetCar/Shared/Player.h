#ifndef PLAYER_H
#define PLAYER_H
#include "Utils.h"
#include "Profile.h"
#include "Tile.h"
#include "Station.h"
#include "Card.h"
#include <set>
#include <fstream>



typedef struct{
  Card stop;
  int line;
}GoalPlayer;

typedef struct {
    bool isInTerminus;
	Tile *curTile;
	Tile *prevTile;
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

    int getMyIdPlayer();
    Tile** getHand();
    Tile* getHand(int position);
    int getLine();
	int getStopCard();
    bool getTravelling();
    Travel* getTravel();
    Profile getProfile();
    std::vector<Station*> getItinerary();

    void setMyIdPlayer(int i);
    void setHand(Tile *h[5]);
    void setHand(Tile h[5]);
    void setHand(Tile *h,int position);
    void setLine(int l);
	void setStopCard(int s);
    void setTravelling(bool travelling);
    void setProfile(Profile p);
    void setItinerary(std::vector<Station*> it);

    bool handIsEmpty();
    std::set<Stroke> strokePossible();
	void printHand();

// 	bool isContain(std::set<Stroke> vs, Stroke s);
    
 private:
    int myIdPlayer;
    Profile profile;
    Tile* hand[5];
    bool isTravelling;
    Travel travel;
    int line;
	int stopCard;
    std::vector<Station*> itinerary;
    
    
    //void strokePossible(int strokePossible[320][4]);


};

#endif



