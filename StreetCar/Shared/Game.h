#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Board.h"
#include "Player.h"

class Game {
    int nbrPlayer;
    vector<Player>players;
    Board board;
    int nbrSquare;

	public:
		Game();
};

#endif
