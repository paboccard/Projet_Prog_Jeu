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
    Board boardTmp;
    Point myTerminus[2][2];
    std::vector<Tile> path;
    //vector<Stop> createOrder();
    Computer(std::vector<vector<Tile> > hands, int whoAmI, GoalPlayer goalP);
    void monteCarlo();
    void allAlea(Board b);
    void easy(Board p);

    Board* getBoard(); 
    Player getMyPlayer();
    int* getPile();
    std::vector<Player> getPlayers();
    void setPlayers(std::vector<Player> player);
    void setPile(int p[12]);
    void setPile(int p[12], int idxChange);
    void setMyPlayer(Player p);

 private:
    Board *board;
    Player myPlayer;
    int pile[12] = {36,30,6,4,10,10,10,6,6,4,2,2};
    std::vector<Player> players;
};

#endif
