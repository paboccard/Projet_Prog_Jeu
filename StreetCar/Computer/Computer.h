#ifndef COMPUTER_H
#define COMPUTER_H
#define INFORMATIONS players[whoAmI-1]
#include <vector>
#include <stdlib.h>    
#include <time.h> 
#include <ctime>       
#include <cstdlib>
#include "../Shared/Player.h"
#include "../Shared/Tile.h"
#include "../Shared/Point.h"
#include "../Shared/Board.h"
#include "../Shared/Pile.h"
class Computer {
    Board board,boardTmp;
	Pile pile;
    Point myTerminus[2][2];
    std::vector<Player> players;
    Pile pile;
    int whoAmI,currentPlayer;
    std::vector<Tile> path;
    vector<Tile> createPath();
 public:
    Computer(std::vector<Player> allPlayers,int whoAmI);
	void test();
	void allAlea(Board b, Pile pile);
};

#endif
