#ifndef GAMESTATENETWORK_H
#define GAMESTATENETWORK_H
#include "../Shared/Board.h"
#include "../Shared/Card.h"
#include "PlayerServerNetwork.h"
#include "clientGuiHandlerNetwork.h"
#include "../Shared/Pile.h"
#include "../Shared/Card.h"
#include "../Shared/StartTravel.h"
#include "../Shared/StartGame.h"
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
#include "../Shared/Debug.h"
#include "../Shared/Quit.h"
#include "../Shared/Profile.h"
#include "../Shared/Validation.h"
#include "../Shared/Goal.h"
#include "../Shared/ProdCons.h"
#include "../Shared/ParamThreadClient.h"
#include "../Shared/IWantPlayNetwork.h"
#include "../Shared/CreateGameNetwork.h"
#include <vector>
#include <pthread.h>

class GameStateNetwork
{
    public:
        int idxhand[NBR_TILE_MAX];
        ProdCons<Pack*> *prodConsCommon;
        ProdCons<Pack*> *prodConsOutputClient[PULLPLAYER];
        pthread_t client[PULLPLAYER];
	std::vector<Profile> profiles;

	bool takePile;
        // creation of the Board
        Board *gameBoard;
	int numGame;

	GameStateNetwork();
        virtual ~GameStateNetwork();

        // initialisation of players and nbrplayers
        void initialization();

        // initialisation of the game to start playing
        void gameInit();

	int getNbrPlayer();
	int getCurrentPlayer();
	int getLastTravelLength();
	bool getStart();
	bool getWon();
	bool getPileWhenTravel();
	std::vector<PlayerServerNetwork*> getPlayers();
	PlayerServerNetwork* getPlayer(int position);
        Pile<Tile*> getPileTile();
        Pile<int> getPileLine();
	Pile<Card> getPileCardStation();
	bool getTravelStarted();
	std::vector<ProdCons<Pack*> *> getCircularQueueClient();

	void setNbrPlayer(int nbr);
	void setCurrentPlayer(int currentP);
	void setLastTravelLength(int travelLengh);
	void setStart(bool begin);
	void setWon(bool win);
	void setPileWhenTravel(bool pileTravel);
	void setPlayers(std::vector<PlayerServerNetwork*> p);
        void setPileTile(Pile<Tile*> p);
        void setPileLine(Pile<int> p);
	void setPileCardStation(Pile<Card> p);
        void setTravelStarted(bool travel); 
	void setCircularQueueClient(std::vector<ProdCons<Pack*> *> prod);

    private:
	int nbrPlayer;
        int currentPlayer;
        int lastTravelLength;
        bool start;
        bool won;
        bool pileWhenTravel;
        std::vector<PlayerServerNetwork*> players;
        Pile<Tile*> pileTile;
        Pile<int> pileLine;
	Pile<Card> pileCardStation;
        bool travelStarted;
	std::vector<ProdCons<Pack*> *> circularQueueClient;
        void initThread();
};

#endif // GAMESTATE_H
