#ifndef INITGAME_H
#define INITGAME_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h" 
#include <iostream>
#include <fstream>
#include <vector>
 
typedef Tile Hand[5];

typedef struct{
StopCard stop;
int line;
}GoalPlayer;
    
class InitGame : public Pack{

public:
std::vector<Hand> hands;
Pile pile;
int idFirstPlayer;
std::vector<GoalPlayer> goalPlayer;

InitGame(std::vector<Hand> h, Pile p, int firstP, std::vector<GoalPlayer> goalP);

friend std::ostream& operator << (std::ostream &f, InitGame &t);
friend std::istream& operator >> (std::istream &f, InitGame &t);

};

#endif
