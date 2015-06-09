#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "../Shared/Board.h"
#include "../Shared/Card.h"
#include "PlayerServer.h"
#include "../Shared/Pile.h"
#include "../Shared/Card.h"
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
#include "../Shared/Validation.h"
#include "../Shared/Goal.h"
#include "../Shared/ProdCons.h"
#include "../Shared/ParamThreadClient.h"
#include "../Shared/Connexion.h"
#include "clientGuiHandler.h"
#include <vector>
#include <pthread.h>
#include <string>

class GameState
{
    public:
        int idxhand[NBR_TILE_MAX];
        ProdCons<Pack*> *prodConsCommon;
        ProdCons<Pack*> *prodConsOutputClient[PULLPLAYER];
        pthread_t client[PULLPLAYER];
        Connexion *connexion;
	
	
        // creation of the Board
        Board *gameBoard;

	GameState();
        virtual ~GameState();

        // initialisation of players and nbrplayers
        void initialization();

        void initThread();
        // initialisation of the game to start playing
        void gameInit();

	int getNbrPlayer();
	int getCurrentPlayer();
	int getLastTravelLength();
	bool getStart();
	bool getWon();
	bool getPileWhenTravel();
	std::vector<PlayerServer*> getPlayers();
	PlayerServer* getPlayer(int position);
        Pile<Tile*> *getPileTile();
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
	void setPlayers(std::vector<PlayerServer*> p);
        void setPileTile(Pile<Tile*> p);
        void setPileLine(Pile<int> p);
	void setPileCardStation(Pile<Card> p);
        void setTravelStarted(bool travel); 
	void setCircularQueueClient(std::vector<ProdCons<Pack*> *> prod);
	void setTakePile(bool b);
	bool getTakePile();
	//friend std::ostream& operator << (std::ostream &f, GameState &t);
	//friend std::istream& operator >> (std::istream &f, GameState &t);


    private:
	bool takePile;
	std::string name;
	int nbrPlayer;
        int currentPlayer;
        int lastTravelLength;
        bool start;
        bool won;
        bool pileWhenTravel;
        std::vector<PlayerServer*> players;
        Pile<Tile*> pileTile;
        Pile<int> pileLine;
	Pile<Card> pileCardStation;
        bool travelStarted;
	std::vector<ProdCons<Pack*> *> circularQueueClient;

};

#endif // GAMESTATE_H
