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
#include "../Shared/Validation.h"
#include "../Shared/StoppedTravel.h"
#include "../Shared/PlayedTravel.h"

#include "PlayerServer.h"
#include "Connexion.h"

using namespace std;


#define PULLPLAYER 6

// sends an error pack to the specified error with the error descriptor
void sendError(int player, error_pack error, GameState *gameState){
    // Here we send the error to the player
    Validation validation = Validation(error);
    gameState->getPlayer(player)->circularQueue->produce(&validation);
    cout << "error " << error  << endl;
}
// handling of a STARTTRAVEL pack
void travelStarted(StartTravel *readPack, GameState *gameState){
    PlayerServer* currentP = gameState->getPlayer(readPack->idPlayer); 
    if (readPack->idPlayer != gameState->getCurrentPlayer())
	sendError(readPack->idPlayer, WRONG_PLAYER, gameState);
    // now we will check if there isn't too many tiles
    else if (readPack->travel.size() > (gameState->getLastTravelLength()+1))
	sendError(readPack->idPlayer, TOO_MANY_TILES, gameState);
    else{
	currentP->setTravelling(true);
	// here we need to check if there is no stop on the way or if there is actualy a way from the current place to the next
	Tile* prevTile;
	int i;
	bool done = false;
	Orientation orientation;
	while ((i < readPack->travel.size()) && !done){
	    if (i==0)
		// we need to check if the first tile is accessible from the current Tile
		prevTile = currentP->getTravel()->curTile;
	    Tile* currentTile = (Tile*) gameState->gameBoard->get(readPack->travel[i].getCoordinates().x, readPack->travel[i].getCoordinates().y);
	    if((prevTile->getCoordinates().x == currentTile->getCoordinates().x)&&(prevTile->getCoordinates().y == currentTile->getCoordinates().y + 1))
		orientation = NORTH;
	    else if((prevTile->getCoordinates().x == currentTile->getCoordinates().x)&&(prevTile->getCoordinates().y == currentTile->getCoordinates().y - 1))
		orientation  = SOUTH;
	    else if((prevTile->getCoordinates().x == currentTile->getCoordinates().x+1)&&(prevTile->getCoordinates().y == currentTile->getCoordinates().y))
		orientation  = EAST;
	    else if((prevTile->getCoordinates().x == currentTile->getCoordinates().x-1)&&(prevTile->getCoordinates().y == currentTile->getCoordinates().y))
		orientation = WEST;
	    else { 
		sendError(readPack->idPlayer, WRONG_WAY, gameState);
		return;
	    }

	    if ((currentTile->getType() == Empty)||(!gameState->gameBoard->adjacentPossible(currentTile, prevTile, orientation))){
		sendError(readPack->idPlayer, WRONG_WAY, gameState);
		return;
	    } else if (currentTile->isStop())
		done = true;
	    i++;
	}
	currentP->getTravel()->prevTile = prevTile;
	currentP->getTravel()->curTile = (Tile*) gameState->gameBoard->get(readPack->travel[i].getCoordinates().x, readPack->travel[i].getCoordinates().x);
	currentP->getTravel()->origin = orientation;
	gameState->setLastTravelLength(i+1);
	gameState->setCurrentPlayer((gameState->getCurrentPlayer() + 1) % gameState->getPlayers().size());
	PlayedTravel* playedTravel = new PlayedTravel(gameState->getCurrentPlayer(), *currentP->getTravel());
	for (int i = 0; i < gameState->getPlayers().size(); i++){
	    gameState->getPlayer(i)->circularQueue->produce(playedTravel);
	
	}

 

    }
} 

// handling of a PLAYTRAVEL pack
void travelPlayed(PlayTravel *readPack, GameState *gameState){
    
    PlayerServer* currentP = gameState->getPlayer(readPack->idPlayer); 
    // checking if right player then if his travel started
    if (readPack->idPlayer != gameState->getCurrentPlayer())
	sendError(readPack->idPlayer, WRONG_PLAYER, gameState);
    else if (!currentP->getTravelling())
	sendError(readPack->idPlayer, TRAVEL_NOT_STARTED, gameState);
    // now we will check if there isn't too many tiles
    else if (readPack->travel.size() > (gameState->getLastTravelLength()+1))
	sendError(readPack->idPlayer, TOO_MANY_TILES, gameState);
    else{
	// here we need to check if there is no stop on the way or if there is actualy a way from the current place to the next
	Tile* prevTile;
	int i;
	bool done = false;
	Orientation orientation;
	while ((i < readPack->travel.size()) && !done){
	    if (i==0)
		// we need to check if the first tile is accessible from the current Tile
		prevTile = currentP->getTravel()->curTile;
	    Tile* currentTile = (Tile*) gameState->gameBoard->get(readPack->travel[i].x, readPack->travel[i].y);
	    if((prevTile->getCoordinates().x == currentTile->getCoordinates().x)&&(prevTile->getCoordinates().y == currentTile->getCoordinates().y + 1))
		orientation = NORTH;
	    else if((prevTile->getCoordinates().x == currentTile->getCoordinates().x)&&(prevTile->getCoordinates().y == currentTile->getCoordinates().y - 1))
		orientation  = SOUTH;
	    else if((prevTile->getCoordinates().x == currentTile->getCoordinates().x+1)&&(prevTile->getCoordinates().y == currentTile->getCoordinates().y))
		orientation  = EAST;
	    else if((prevTile->getCoordinates().x == currentTile->getCoordinates().x-1)&&(prevTile->getCoordinates().y == currentTile->getCoordinates().y))
		orientation = WEST;
	    else { 
		sendError(readPack->idPlayer, WRONG_WAY, gameState);
		return;
	    }

	    if ((currentTile->getType() == Empty)||(!gameState->gameBoard->adjacentPossible(currentTile, prevTile, orientation))){
		sendError(readPack->idPlayer, WRONG_WAY, gameState);
		return;
	    } else if (currentTile->isStop())
		done = true;
	    i++;
	}
	currentP->getTravel()->prevTile = prevTile;
	currentP->getTravel()->curTile = (Tile*) gameState->gameBoard->get(readPack->travel[i].x, readPack->travel[i].x);
	currentP->getTravel()->origin = orientation;
	gameState->setLastTravelLength(i+1);
	gameState->setCurrentPlayer((gameState->getCurrentPlayer() + 1) % gameState->getPlayers().size());
	PlayedTravel* playedTravel = new PlayedTravel(gameState->getCurrentPlayer(), *currentP->getTravel());
	for (int i = 0; i < gameState->getPlayers().size(); i++){
	    gameState->getPlayer(i)->circularQueue->produce(playedTravel);
	
	}

    }
}

// handling of a STOPTRAVEL pack
void travelStopped(StopTravel *readPack, GameState *gameState){

    // TO-DO checking validation
    if (readPack->idPlayer != gameState->getCurrentPlayer())
	sendError(readPack->idPlayer, WRONG_PLAYER, gameState);
    else if (!gameState->getPlayer(readPack->idPlayer)->getTravelling())
	sendError(readPack->idPlayer, TRAVEL_NOT_STARTED, gameState);
    else {
	// TO-DO throw validation and update of the board
	gameState->getPlayer(readPack->idPlayer)->setTravelling(false);
	StoppedTravel* stoppedTravel = new StoppedTravel((readPack->idPlayer + 1 % gameState->getPlayers().size()));
        for (int i = 0; i < gameState->getPlayers().size(); i++){
	    gameState->getPlayer(i)->circularQueue->produce(stoppedTravel);
	}

    }
}

// handling of a PLAYTILE pack
void tilePlayed(PlayTile *readPack, GameState *gameState){
    vector<Tile*> tilePlay;
    cout << "Player in readPack : " << *readPack << endl;
    cout << "current Player : " << gameState->getCurrentPlayer() << endl;
    if (readPack->idPlayer != gameState->getCurrentPlayer()){
        sendError(readPack->idPlayer, WRONG_PLAYER, gameState);
        gameState->takePile = false;
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
            cout << "players hand : " << playersHand[i]->getType() << endl;
	    cout << "played tile : " << readPack->tiles[i]->getType() << endl;
	    sendError(gameState->getCurrentPlayer(), TILE_NOT_IN_HAND, gameState);
	    gameState->takePile = false;
	    if (i > 0)
		gameState->gameBoard->undoStroke();
	    return;
	}
    
    for (int i = 0; i < NBR_TILE_MAX; i++){
        // We check if it is a replace move
	Tile* currentSquare = playersHand[gameState->idxhand[i]];
        Square *boardSquare = gameState->gameBoard->get(currentSquare->getCoordinates());
        if (boardSquare->isEmpty()){
            // this is not a replace move
            if (!gameState->gameBoard->putPossible(currentSquare->getCoordinates(), currentSquare)){
		sendError(gameState->getCurrentPlayer(), IMPOSSIBLE_PLAY, gameState);
		cout << "can't put tile " << currentSquare->getType() << " here" << endl;
		cout << "x : " << currentSquare->getCoordinates().x << "y : " << currentSquare->getCoordinates().y << endl;
		gameState->takePile = false;
		if (i > 0)
		    gameState->gameBoard->printConsole();
		gameState->gameBoard->undoStroke();
		return;
	    } else {
		// use new "put" function
		gameState->gameBoard->put(currentSquare);
	    }
	} else {
	    // this is a replace move, we check if you can put the card here
	    if (!gameState->gameBoard->changePossible((Tile*)boardSquare,currentSquare)){
		sendError(gameState->getCurrentPlayer(), IMPOSSIBLE_PLAY, gameState);
		cout << "can't put tile " << currentSquare << " here" << endl;
		gameState->takePile = false;
		if (i > 0)
		    gameState->gameBoard->undoStroke();
		return;
	    } else {
		// use new "change" function
		gameState->gameBoard->change((Tile*)boardSquare,currentSquare);
	    }
	}
	
    }
    gameState->takePile = true;
    // if we are here, both tiles were validated
    /*    for (int i = 0; i < NBR_TILE_MAX; i++){
	  Tile* currentSquare = playersHand[gameState->idxhand[i]];
	  Square *boardSquare = gameState->gameBoard->get(currentSquare->getCoordinates());
	  tilePlay.push_back(currentSquare);
	  gameState->gameBoard->change((Tile*)boardSquare, currentSquare);
	  }*/
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
    // the player sent the tiles he wanted to take from the hand of a player who started his travel
    // we first check if it is the right player and if it is the time to play
    if (!gameState->getPileWhenTravel())
	sendError(gameState->getCurrentPlayer(), TIME_FOR_REGULAR_PILE, gameState);
    // if the player doesn't want to take a card form the other players, it is a regularPile
    else if (readPack->idHands.size() > 2)
	sendError(gameState->getCurrentPlayer(), TOO_MANY_TILES, gameState);
    else {
	vector<int> idHandCurrentP;
	vector<Tile> tilePile;
	PlayerServer* currentP = gameState->getPlayer(gameState->getCurrentPlayer());
	tilePile.clear();
	idHandCurrentP.clear();

	for (int i = 0; i < NBR_TILE_MAX; i++) {
	    if (currentP->getHand(i)->getType() == Empty)
		idHandCurrentP.push_back(i);
	}
	if (idHandCurrentP.size() < readPack->idHands.size())	
	    sendError(gameState->getCurrentPlayer(), TOO_MANY_TILES, gameState);
	else {	    
	    
	    for (int i = 0; i < idHandCurrentP.size(); i++) {
		int idPlayer = readPack->idPlayers.back();
		int idxHand = readPack->idHands.back();
		PlayerServer* playerPile = gameState->getPlayer(readPack->idPlayers[i]);
		currentP->setHand(playerPile->getHand(idxHand), idHandCurrentP[i]);
		readPack->idHands.pop_back();
		readPack->idPlayers.pop_back();
	    }
	    // we take what is left from the pile 
	    while( tilePile.size() < 2 && !gameState->getPileTile()->isEmpty()){
		currentP->setHand(gameState->getPileTile()->take(), idHandCurrentP[tilePile.size()]);
		tilePile.push_back(*currentP->getHand(idHandCurrentP[tilePile.size()]));
	    }
	    PilePlayer pilePlayer = PilePlayer(gameState->getCurrentPlayer(), (gameState->getCurrentPlayer()+1) % gameState->getNbrPlayer(), tilePile, idHandCurrentP);
	    // we change the next player
	    gameState->setCurrentPlayer((gameState->getCurrentPlayer()+1) % gameState->getNbrPlayer());
	    
	    for (int i = 0; i < gameState->getNbrPlayer(); i++){
		gameState->getPlayer(i)->circularQueue->produce(&pilePlayer);
	    }
	}
    }
}

void regularPile(GameState* gameState){
    vector<Tile> tilePile;
    vector<int> idxT;
    cout << "regularPile in" << endl;
    idxT.clear();
    
    for (int i = 0; i<HAND_SIZE; i++){
	if (gameState->getPlayer(gameState->getCurrentPlayer())->getHand(i)->getType() == -1){
	    
	    gameState->getPlayer(gameState->getCurrentPlayer())->setHand(gameState->getPileTile()->take(),i);
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

	Pack* readPack = gameState->prodConsCommon->consume();//getPlayer(gameState->getCurrentPlayer())->circularQueue->consume();
	if (!gameState->getPileWhenTravel()){
	    // if the pack was sent by the current player we call the appropriate function to validate or not the move, else we do nothing and wait for the write player to communicate.
	    switch (readPack->idPack) {
	    case STARTTRAVEL :
		travelStarted((StartTravel*)&readPack, gameState);
		break;
	    case PLAYTRAVEL :
		travelPlayed((PlayTravel*)&readPack, gameState);
		break;
	    case STOPTRAVEL :
		travelStopped((StopTravel*)&readPack, gameState);
		break;
	    case PLAYTILE :
		tilePlayed((PlayTile*)readPack, gameState);
		if (!gameState->getPileWhenTravel() && gameState->takePile)
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

