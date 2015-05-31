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
void tileplayed(PlayTile *readPack, GameState *gameState){
    if (readPack->idPlayer != gameState->currentPlayer){
        sendError(readPack->idPlayer, WRONG_PLAYER);
        return;
        }
    for(int i = 0; i < NB_TILE_MAX; i++){
        gameState->idxhand[i] = readPack->idxHand[i];

    }
    Tile playersHand[HAND_SIZE];
    for (int i = 0; i < HAND_SIZE; i++)
        playersHand[i] = gameState->players[gameState->currentPlayer].hand[i];
    // checking if tile actualy in hand
    for (int i = 0; i< NB_TILE_MAX; i++){
        if (playersHand[i].type != readPack->tiles[i].type){
            sendError(gameState->currentPlayer, TILE_NOT_IN_HAND);
        }
    }

    for (int i = 0; i < NB_TILE_MAX; i++){
        // We check if it is a replace move
        Square boardSquare = gameState->gameBoard.get(playersHand[gameState->idxhand[i]].coordinates.x, playersHand[gameState->idxhand[i]].coordinates.y);
        if (boardSquare.isEmpty()){
            // this is not a replace move
            if (gameState->gameBoard.putPossible(playersHand[gameState->idxhand[i]].coordinates.x, playersHand[gameState->idxhand[i]].coordinates.y, playersHand[gameState->idxhand[i]])){
                // if the tile can be played we check if it is next to a stop
                Stop* stop = gameState->gameBoard.nextToStop(playersHand[gameState->idxhand[i]].coordinates.x, playersHand[gameState->idxhand[i]].coordinates.y) ;
                if( stop != NULL){
                    // stop represent the adjacent stop, if there is no Tile associated to it, we associate the stop to the pointer of the tile on the board and the tile is set as a stop tile
                    if (!(stop->isLinked())){
                        playersHand[gameState->idxhand[i]].isStop = true;
                        stop->linked = (Tile *)gameState->gameBoard.getPointer(playersHand[gameState->idxhand[i]].coordinates.x, playersHand[gameState->idxhand[i]].coordinates.y);
                    }
                }

            } else {
                // the tile can't be set here we get an impossible play error
                sendError(gameState->currentPlayer, IMPOSSIBLE_PLAY);
                return;
            }
        } else {
            // this is a replace move, we check if you can put the card here
            Square squareTmp = gameState->gameBoard.get(playersHand[gameState->idxhand[i]].coordinates.x, playersHand[gameState->idxhand[i]].coordinates.y);
            Tile tileTmp;
            if (squareTmp.isTile()){
                tileTmp = Tile(squareTmp.type, 0);
            } else {
                sendError(gameState->currentPlayer, IMPOSSIBLE_PLAY);
                return;
            }


            if (playersHand[gameState->idxhand[i]].change(tileTmp)){
                // then we check if we can put it
                if (!gameState->gameBoard.putPossible(playersHand[gameState->idxhand[i]].coordinates.x, playersHand[gameState->idxhand[i]].coordinates.y, playersHand[gameState->idxhand[i]])){

                    // the tile can't be set here we get an impossible play error
                    sendError(gameState->currentPlayer, IMPOSSIBLE_PLAY);
                    return;
                }

            }


        }
    }
    vector<Tile> played;
    // if the tests above suceed, we update the local board and hand
    for (int i = 0; i<NB_TILE_MAX; i++) {
        played[i] = playersHand[gameState->idxhand[i]];
        // to see how to produce in pack
        gameState->gameBoard.set(played[i].coordinates.x, played[i].coordinates.y, played[i]);
    }

    // creation of a responce pack
    PlayedTile playedTile = PlayedTile(played);
    for (int i = 0; i < gameState->players.size(); i++){
        gameState->players[i].circularQueue->produce(&playedTile);
    }
    // if the travel started, we wait for a new pack from the player, PILEWHENTRAVEL pack
    if (gameState->travelStarted){
        gameState->pileWhenTravel = true;
        }
}
// handling of a PILEWHENTRAVEL pack
void pilewhentravel(PileWhenTravel *readPack, GameState *gameState){

    // TO-DO checking validation

    // throw validation and update of the board
}

void regularPile(GameState* gameState){

    for (int i = 0; i<HAND_SIZE; i++)
        gameState->players[gameState->currentPlayer].hand[i] = gameState->pile.take();

    PilePlayer pilePlayer = PilePlayer(gameState->currentPlayer, gameState->currentPlayer++ % gameState->nbrPlayer, gameState->players[gameState->currentPlayer].hand);
    // we change the next player
    gameState->currentPlayer = gameState->currentPlayer++ % gameState->nbrPlayer;

    for (int i = 0; i < gameState->nbrPlayer; i++){
        gameState->players[i].circularQueue->produce(&pilePlayer);
    }


}


int main(int argc, char **argv){
    GameState gameState = GameState();
    int cardsInHand[2];

    //    while(!start){
    // TO-DO : initialization of the game
    // must fill players with a vector of PlayerServer containing the list of Player + a ProdCons associated to him

    // wait for connexions, the first in is the host then new players for online game, else the gui for local games with all human players then the computers connect one by one
    // when the host (online game) or the gui (local game) sends the message to start, set start to true and this is the end of the initialization.
    Connexion connexion = Connexion();

    ProdCons<Pack*> *prodConsCommon = new ProdCons<Pack*>();
    pthread_t client[PULLPLAYER];
    ProdCons<Pack*> *prodConsOutputClient[PULLPLAYER];


    for (int i = 0; i<PULLPLAYER; i++){
        prodConsOutputClient[i] = new ProdCons<Pack*>();
        ParamThread paramThread = {prodConsOutputClient[i],prodConsCommon,connexion.sockfd,&connexion.serv_addr, &connexion.cli_addr};
        if (pthread_create(&client[i], NULL, clientOutputHandler,(void *)(&paramThread))==0){
            cout << "End of event thread client " << i << endl;
        }else
            cout << "ERROR, impossible to create client " << i << endl;
    }
    cout << endl;

    Pack * pack;
    int nbrMax;
    NewPlayerAdd *np;
    while (!gameState.start){

        pack = prodConsCommon->consume();
        switch(pack->idPack){
        case IWANTPLAY:
	    {
		IWantPlay *p = (IWantPlay*)pack;
		if (nbrPlayer == nbrMax){
		    //TODO MESSAGE ERROR
		    cout << "to much players" << endl;
		}else{
		    nbrPlayer++;
		    np = new NewPlayerAdd(p->profile, nbrPlayer);
		    PlayerServer currentP = PlayerServer();
		    currentP.profile = p->profile;
		    currentP.myIdPlayer = nbrPlayer;
		    players.push_back(currentP);
		    cout << "Nom du joueur entré : " << p->profile.name << endl;
		    players[nbrPlayer].circularQueue->produce(new YourIdPlayer(nbrPlayer));
		    //		    players[nbrPlayer].profile = p->profile;
		    //players[nbrPlayer].isTravelling = false;
		    for (unsigned int i = 0; i<players.size(); i++)
			players[i].circularQueue->produce(np);
		}
	    }
            break;
        case STARTGAME:
            start = true;
            break;
        case CIRCULARQUEUECLIENT:
	    {
		CircularQueueClient *c = (CircularQueueClient*)pack;
		PlayerServer ps = PlayerServer(c->prodConsClient);
		players.push_back(ps);
	    }
            break;
        case CREATEGAME:
	    {
		CreateGame *c = (CreateGame*)pack;
		nbrMax = c->nbrPlayer;
		players.clear();
		players.resize(nbrMax);
		cout << "nombre max de player : " << nbrMax << endl;
	    }
	    break;
	case DEBUG:
	    {
		Debug *d = new Debug("Message_bien_reçu");
		for (unsigned int i = 0; i<players.size(); i++)
		    players[i].circularQueue->produce(d);
	    }
        default:
            break;
        }
	delete pack;
    }


    ///////////////////////////////
    // Game initialisation
    ///////////////////////////////

    gameState.GameInit();

    ///////////////////////////////
    // here starts the referee
    ///////////////////////////////

    int readPlayer;

    while(!gameState.won){
        Pack* readPack = gameState.prodCons->consume();
        if (!gameState.pileWhenTravel){
            // if the pack was sent by the current player we call the appropriate function to validate or not the move, else we do nothing and wait for the write player to communicate.
            switch (readPack->idPack) {
            case STARTTRAVEL :
                travelstarted((StartTravel*)&readPack, &gameState);
                break;
            case PLAYTRAVEL :
                travelplayed((PlayTravel*)&readPack, &gameState);
                break;
            case STOPTRAVEL :
                travelstopped((StopTravel*)&readPack, &gameState);
                break;
            case PLAYTILE :
                tileplayed((PlayTile*)&readPack, &gameState);
                if (!gameState.pileWhenTravel)
                    regularPile(&gameState);
                break;
            default :   //error, we do nothing
                break;
            }
        } else {
            switch (readPack->idPack) {
                case PILEWHENTRAVEL :
                    gameState.currentPlayer++;
                    pilewhentravel((PileWhenTravel*)&readPack, &gameState);
                    gameState.pileWhenTravel = false;
                    break;
                default :   //error, we do nothing
                    break;
                }
        }

        close(connexion.sockfd);

    }

    for (int i = 0; i<5; i++)
        pthread_join(client[i], NULL);

    delete prodConsCommon;
    for (int i=0; i<5; i++)
        delete prodConsOutputClient[i];

    return 0;
}

