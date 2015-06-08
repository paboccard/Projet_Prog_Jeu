#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Board.h"
#include "Player.h"

class Game {
    int nbrPlayer;
    std::vector<Player>players;
    Board board;

    int nbrSquare;

	public:
		Game();
};

#endif
