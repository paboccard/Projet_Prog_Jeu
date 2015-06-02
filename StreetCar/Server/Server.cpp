#include "clientGuiHandler.h"
#include "ParamThreadClient.h"
#include "../Shared/Packs.h"
#include "../Shared/Pack.h"
#include "../Shared/Board.h"
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
#include "../Shared/PilePlayer.h"
#include "GameState.h"

#include "PlayerServer.h"
#include "Connexion.h"

using namespace std;


#define NB_TILE_MAX 2
#define PULLPLAYER 6

// sends an error pack to the specified error with the error descriptor
void sendError(int player, error_pack error){
    // TO-DO send error to the player
}
// handling of a STARTTRAVEL pack
void travelstarted(StartTravel *readPack, GameState *gameState){
    /*    Pack answerPack;
    // TO-DO checking validation
    if (readPack.travel.size() != lastTravelLength + 1)
    send_error(readPack.idPlayer, TOO_MANY_TILES);
    else if (!Board.checkWay(traveol))
    send_error(readPack.idPlayer, WRONG_WAY);
    else {
    // the move is accepted, the local board is modified as well as the currentPlayer and lastTravelLength
    lastTravelLength = readPack.travel.size();
    currentPlayer++;
    //
    // TO-DO throw validation and update of the board
    }
    */
} /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// handling of a PLAYTRAVEL pack
void travelplayed(PlayTravel *readPack, GameState *gameState){
    Pack* aswerPack;

    // TO-DO checking validation

    // TO-DO throw validation and update of the board

}

// handling of a STOPTRAVEL pack
void travelstopped(StopTravel *readPack, GameState *gameState){

    // TO-DO checking validation

    // TO-DO throw validation and update of the board
}

// handling of a PLAYTILE pack
void tilePlayed(PlayTile *readPack, GameState *gameState){
    vector<Tile> tilePlay;
    if (readPack->idPlayer != gameState->getCurrentPlayer()){
        sendError(readPack->idPlayer, WRONG_PLAYER);
        return;
    }
    
    for(int i = 0; i < NBR_TILE_MAX; i++){
        gameState->idxhand[i] = readPack->idxHand[i];
    }
    
    Tile **playersHand;
    playersHand = gameState->getPlayer(readPack->idPlayer)->getHand();
    // checking if tile actualy in hand
    for (int i = 0; i< NBR_TILE_MAX; i++)
        if (playersHand[i]->getType() != readPack->tiles[i]->getType()){
            sendError(gameState->getCurrentPlayer(), TILE_NOT_IN_HAND);
	    return;
	}
    
    for (int i = 0; i < NBR_TILE_MAX; i++){
        // We check if it is a replace move
	Tile* currentSquare = playersHand[gameState->idxhand[i]];
        Square *boardSquare = gameState->gameBoard.get(currentSquare->getCoordinates());
        if (boardSquare->isEmpty()){
            // this is not a replace move
            if (!gameState->gameBoard.putPossible(currentSquare->getCoordinates(), currentSquare)){
		sendError(gameState->getCurrentPlayer(), IMPOSSIBLE_PLAY);
		return;
	    }
	}else {
	    // this is a replace move, we check if you can put the card here
	    if (!gameState->gameBoard.changePossible((Tile*)boardSquare,currentSquare)){
		sendError(gameState->getCurrentPlayer(), IMPOSSIBLE_PLAY);
		return;
	    }
	}
	tilePlay.push_back(*currentSquare);
	gameState->gameBoard.change((Tile*)boardSquare, currentSquare);
    }
    // creation of a responce pack
    vector<int> idxT;
    idxT.push_back(readPack->idxHand[0]);
    idxT.push_back(readPack->idxHand[1]);
    PlayedTile *playedTile = new PlayedTile(tilePlay,idxT);
    for (int i = 0; i < gameState->getPlayers().size(); i++){
	gameState->getPlayer(i)->circularQueue->produce(playedTile);
    }
    // if the travel started, we wait for a new pack from the player, PILEWHENTRAVEL pack
    if (gameState->getTravelStarted()){
	gameState->setPileWhenTravel(true);
    }
}

// handling of a PILEWHENTRAVEL pack
void pilewhentravel(PileWhenTravel *readPack, GameState *gameState){
    
    // TO-DO checking validation
    
    // throw validation and update of the board
}

void regularPile(GameState* gameState){
    vector<Tile> tilePile;
    vector<int> idxT;
    idxT.clear();
    tilePile.clear();
    for (int i = 0; i<HAND_SIZE; i++){
	if (gameState->getPlayer(gameState->getCurrentPlayer())->getHand(i) == NULL){
	    gameState->getPlayer(gameState->getCurrentPlayer())->setHand(gameState->getPileTile().take(),i);
	    tilePile.push_back(*gameState->getPlayer(gameState->getCurrentPlayer())->getHand(i));
	    idxT.push_back(i);
	}
    }
    
    PilePlayer pilePlayer = PilePlayer(gameState->getCurrentPlayer(), (gameState->getCurrentPlayer()+1) % gameState->getNbrPlayer(), tilePile, idxT);
    // we change the next player
    gameState->setCurrentPlayer((gameState->getCurrentPlayer()+1) % gameState->getNbrPlayer());

    for (int i = 0; i < gameState->getNbrPlayer(); i++){
	gameState->getPlayer(i)->circularQueue->produce(&pilePlayer);
    }


}


int main(int argc, char **argv){


    GameState *gameState;
    int cardsInHand[2];

    //    while(!start){
    // TO-DO : initialization of the game
    // must fill players with a vector of PlayerServer containing the list of Player + a ProdCons associated to him

    // wait for connexions, the first in is the host then new players for online game, else the gui for local games with all human players then the computers connect one by one
    // when the host (online game) or the gui (local game) sends the message to start, set start to true and this is the end of the initialization.
    //    Connexion connexion = Connexion();

    //    gameState = GameState(connexion);
    
    gameState = new GameState();
    gameState->initThread();
    gameState->initialization();

    ///////////////////////////////
    // Game initialisation
    ///////////////////////////////

    gameState->gameInit();

    ///////////////////////////////
    // here starts the referee
    ///////////////////////////////

    int readPlayer;

    while(!gameState->getWon()){

	Pack* readPack = gameState->getPlayer(gameState->getCurrentPlayer())->circularQueue->consume();
	if (!gameState->getPileWhenTravel()){
	    // if the pack was sent by the current player we call the appropriate function to validate or not the move, else we do nothing and wait for the write player to communicate.
	    switch (readPack->idPack) {
	    case STARTTRAVEL :
		travelstarted((StartTravel*)&readPack, gameState);
		break;
	    case PLAYTRAVEL :
		travelplayed((PlayTravel*)&readPack, gameState);
		break;
	    case STOPTRAVEL :
		travelstopped((StopTravel*)&readPack, gameState);
		break;
	    case PLAYTILE :
		tilePlayed((PlayTile*)&readPack, gameState);
		if (!gameState->getPileWhenTravel())
		    regularPile(gameState);
		break;
	    default :   //error, we do nothing
		break;
	    }
	} else {
	    switch (readPack->idPack) {
	    case PILEWHENTRAVEL :
		gameState->setCurrentPlayer(gameState->getCurrentPlayer()+1);
		pilewhentravel((PileWhenTravel*)&readPack, gameState);
		gameState->setPileWhenTravel(false);
		break;
	    default :   //error, we do nothing
		break;
	    }
	}
	close(gameState->connexion->sockfd);
    }

    for (int i = 0; i<PULLPLAYER; i++)
	pthread_join(gameState->client[i], NULL);

    delete gameState->prodConsCommon;
    for (int i=0; i<PULLPLAYER; i++)
	delete gameState->prodConsOutputClient[i];

    return 0;
}

