#ifndef GOAL_H
#define GOAL_H

#include "Pack.h"
#include "Packs.h"
#include "Utils.h"
#include "Tile.h" 
#include "Pile.h" 
#include "Player.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Goal : public Pack{
  
 public:
    GoalPlayer goalPlayer;
    
    Goal();
    Goal(GoalPlayer goalP);

    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, Goal &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, Goal &t){
	t.read(f);
	return f;
    };
  
};

#endif
 
