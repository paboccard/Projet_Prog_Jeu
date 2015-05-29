#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "../Shared/Board.h"
#include "../Shared/Card.h"
#include "PlayerServer.h"
#include "../Shared/Pile.h"
#include "../Shared/StartTravel.h"
#include "../Shared/PlayTravel.h"
#include "../Shared/StopTravel.h"
#include "../Shared/PlayTile.h"
#include "../Shared/Pile.h"
#include "../Shared/PileWhenTravel.h"
#include "../Shared/PileTarget.h"
#include "../Shared/Card.h"
#include "../Shared/InitGame.h"
#include "../Shared/PlayedTile.h"
#include "../Shared/CreateGame.h"
#include "../Shared/IWantPlay.h"
#include "../Shared/NewPlayerAdd.h"
#include "../Shared/StartGame.h"
#include "../Shared/YourIdPlayer.h"
#include "CircularQueueClient.h"
#include "../Shared/Debug.h"
#include "../Shared/Quit.h"
#include "../Shared/ProdCons.h"
#include "../Shared/ParamThreadClient.h"
#include "Connexion.h"
#include "clientGuiHandler.h"
#include <vector>
#include <pthread.h>

#define PULLPLAYER 6

class GameState
{
    public:
        int nbrPlayer;
        int currentPlayer;
        int lastTravelLength;
        bool start;
        bool won;
        bool pileWhenTravel;
        std::vector<PlayerServer*> players;
        Pile pile;
        bool travelStarted;
	int idxhand[2];
	ProdCons<Pack*> *prodConsCommon;
	ProdCons<Pack*> *prodConsOutputClient[PULLPLAYER];
	pthread_t client[PULLPLAYER];
	Connexion *connexion;


        // creation of the Board
        Board gameBoard;

	GameState();
        virtual ~GameState();

        // initialisation of players and nbrplayers
        void initialization();
	void initThread();
        // initialisation of the game to start playing
        void gameInit();


    protected:
    private:
};

#endif // GAMESTATE_H
