#ifndef INITGAME_H
#define INITGAME_H

#include "../Shared/Pack.h"
#include "../Shared/Packs.h"
#include "../Shared/Utils.h"
#include "../Shared/Tile.h" 
#include "../Shared/Pile.h" 
#include "../Shared/Card.h" 
#include <iostream>
#include <fstream>
#include <vector>
#include <array>

typedef Tile Hand[5];

typedef struct{
    Card stop;
    int line;
}GoalPlayer;

class InitGame : public Pack{

 public:
    std::vector<std::array<Tile,5>> hands;
    Pile pile;
    int idFirstPlayer;
    std::vector<GoalPlayer> goalPlayer;
    
    InitGame(std::vector<std::array<Tile,5>> h, Pile p, int firstP, std::vector<GoalPlayer> goalP);
    
    friend std::ostream& operator << (std::ostream &f, InitGame &t);
    friend std::istream& operator >> (std::istream &f, InitGame &t);
    
};

#endif
