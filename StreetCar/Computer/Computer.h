#ifndef COMPUTER_H
#define COMPUTER_H

#define TRACE 0

#include <vector>
#include <set>
#include <stdlib.h>    
#include <time.h> 
#include <ctime>       
#include <cstdlib>
#include <algorithm>
#include "../Shared/Player.h"
#include "../Shared/Tile.h"
#include "../Shared/Point.h"
#include "../Shared/Board.h"
#include "../Shared/Utils.h"
#include "../Shared/Pile.h"

class Computer {
 public:
    Board board,boardTmp;
    Player myPlayer;
    Pile pile;
    Point myTerminus[2][2];
    std::vector<Player> players;
    int whoAmI,currentPlayer;
    std::vector<Tile> path;
    vector<Stop> createOrder();
    
    Computer(std::vector<vector<Tile> > hands, int IAm, Pile p, GoalPlayer goalP);
    
    void monteCarlo();
    void allAlea(Board b, Pile pile);
    void easy(Board p);
};

#endif
