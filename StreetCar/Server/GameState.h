#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "../Shared/Board.h"
#include "../Shared/Card.h"
#include "../Shared/InitGame.h"
#include "PlayerServer.h"
#include "../Shared/Pile.h"
#include "../Shared/Board.h"
#include <vector>

class GameState
{
    public:
        int nbrPlayer;
        int currentPlayer;
        int lastTravelLength;
        bool start;
        bool won;
        bool pileWhenTravel;
        std::vector<PlayerServer> players;
        Pile pile;
        bool travelStarted;

        // creation of the Board
        Board gameBoard;

        GameState();
        virtual ~GameState();

        // initialisation of players and nbrplayers
        void Initialization();
        // initialisation of the game to start playing
        void GameInit();


    protected:
    private:
};

#endif // GAMESTATE_H
