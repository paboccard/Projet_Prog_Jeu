#ifndef COMPUTER_H
#define COMPUTER_H

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
#include "../Shared/Station.h"
#include "../Shared/PlayTile.h"
#define ABS(I) ( ((I)<0) ? -(I):(I) )


typedef struct {
	Point p;
	Orientation prec;
	Orientation suiv;
} ElementPath;

class Computer {
 public:
    vector<Point> createOrder();
    Computer(std::vector<vector<Tile*> > hands, int IAm, GoalPlayer goalP);


//	void monteCarlo();
//	void allAlea(Board b);
    PlayTile easy();
    
    PlayTile medium(Board p);
    Board* getBoard(); 
    Player getMyPlayer();
    int* getPile();
    std::vector<Player*> getPlayers();
    Player* getPlayers(int position);
    void setPlayers(std::vector<Player*> player);
    void setPile(int p[12]);
    void setPile(int idxChange);
    void setMyPlayer(Player p);
	bool isOnThePath(Point p);
	bool putPathPossible(ElementPath e, Tile *t);
	ElementPath pathGet(Point p);
	bool isBlock();

 private:
    Board *board;
	bool block;
    Point myTerminus[2][2];
    std::vector<ElementPath> path;
    Player myPlayer;
    int pile[12] = {36,30,6,4,10,10,10,6,6,4,2,2};
    std::vector<Player*> players;
};

#endif
