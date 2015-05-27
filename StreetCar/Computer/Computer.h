#ifndef COMPUTER_H
#define COMPUTER_H
#define INFORMATIONS players[whoAmI-1]
#include <vector>
#include "../Shared/Player.h"
#include "../Shared/Tile.h"
#include "../Shared/Point.h"
#include "../Shared/Board.h"
#include "../Shared/Pile.h"
class Computer {
    Board board,boardTmp;
    Point myTerminus[2][2];
    std::vector<Player> players;
    Pile pile;
    int whoAmI,currentPlayer;
    std::vector<Tile> path;
    vector<Tile> createPath();
 public:
    Computer(std::vector<Player> allPlayers,int whoAmI);
};

#endif
