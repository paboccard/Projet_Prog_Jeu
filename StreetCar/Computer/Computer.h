#ifndef COMPUTER_H
#define COMPUTER_H

#define INFORMATIONS players[whoAmI]
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
    Pile pile;
    Point myTerminus[2][2];
    std::vector<Player> players;
    int whoAmI,currentPlayer;
    std::vector<Tile> path;
    vector<Stop> createOrder();
    Computer(std::vector<Player> allPlayers,int whoAmI, Pile p);
    void monteCarlo();
    void allAlea(Board b, Pile pile);
};

#endif
