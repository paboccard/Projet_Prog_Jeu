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
//#include "../Shared/PileWhenTravel.h"

#include "PlayerServer.h"
#include <cstdlib>
#include <pthread.h>
#include "clientGuiHandler.h"

using namespace std;


int nbrPlayer;
int currentPlayer;
bool won = false;
#define NB_TILE_MAX 2

// sends an error pack to the specified error with the error descriptor
void sendError(int player, error_pack error){
    // TO-DO send error to the player
}
// handling of a STARTTRAVEL pack
void travelstarted(Pack readPack){
    Pack answerPack;

    // TO-DO checking validation

}

// handling of a PLAYTRAVEL pack
void travelplayed(Pack readPack){
    Pack aswerPack;

    // TO-DO checking validation

    // TO-DO throw validation

}

// handling of a STOPTRAVEL pack
void travelstopped(Pack readPack){

    // TO-DO reading the pack

    // TO-DO checking validation

    // TO-DO throw validation
}

// handling of a PLAYTILE pack
void tileplayed(PlayTile *readPack, int currentPlayer, Board gameBoard, vector<PlayerServer> players){
    int idxhand[NB_TILE_MAX];
    for(int i = 0; i < NB_TILE_MAX; i++){
        idxhand[i] = readPack->idxHand[i];
    }
    Tile playersHand[HAND_SIZE];
    for (int i = 0; i < HAND_SIZE; i++)
        playersHand[i] = players[currentPlayer].hand[i];
    // checking if tile actualy in hand
    for (int i = 0; i< NB_TILE_MAX; i++){
        if (playersHand[i].type != readPack->tiles[i].type){
            sendError(currentPlayer, TILE_NOT_IN_HAND);
        }
    }


    // We check if it is a replace move
    Square boardSquare = gameBoard.get(playersHand[idxhand[0]].coordinates.x, playersHand[idxhand[0]].coordinates.y);
    if (boardSquare.isEmpty()){
        // this is not a replace move
        if (gameBoard.putPossible(playersHand[idxhand[0]].coordinates.x, playersHand[idxhand[0]].coordinates.y, playersHand[idxhand[0]])){
            // we put the card on the board and check the second move.
        } else {
            // the tile can't be set here we get an impossible play error
            sendError(currentPlayer, IMPOSSIBLE_PLAY);
        }
    }

    // TO-DO throw validation
}

int main(int argc, char **argv){
    int nbrPlayer;
    int currentPlayer;
    int lastTravelLength = 0;
    bool start = false;
    bool won = false;
    vector<PlayerServer> players;

    //currentPlayer = rand() % nbrPlayer;


    //    while(!start){
    // TO-DO : initialization of the game
    // must fill players with a vector of PlayerServer containing the list of Player + a ProdCons associated to him

    // wait for connexions, the first in is the host then new players for online game, else the gui for local games with all human players then the computers connect one by one
    // when the host (online game) or the gui (local game) sends the message to start, set start to true and this is the end of the initialization.
    //gameBoard = Board();
      
    ProdCons<Pack> *prodConsOutputAutomate = new ProdCons<Pack>();
    ProdCons<Pack> *prodConsOutputClientGui = new ProdCons<Pack>();
    ProdCons<Pack> *prodConsCommon = new ProdCons<Pack>();

    pthread_t clientGuiInput;
    pthread_t clientGuiOutput;
    pthread_t automateInput;
    pthread_t automateOutput;

    cout << endl;
    if (pthread_create(&clientGuiInput, NULL, clientGuiInputHandler,(void *)(prodConsCommon))==0){
	if (pthread_create(&clientGuiOutput, NULL, clientGuiOutputHandler,(void *)(prodConsOutputClientGui))==0){
	    if (pthread_create(&automateInput, NULL, automateInputHandler,(void *)(prodConsCommon))==0){
		if (pthread_create(&automateOutput, NULL, automateOutputHandler,(void *)(prodConsOutputAutomate))==0){
		        
		    pthread_join(automateOutput, NULL);
		    cout << "End of event thread automateOutput" << endl;
		}else
		    cout << "ERROR, impossible to create automateOutput thread" << endl;
		  
		pthread_join(automateInput, NULL);
		cout << "End of event thread automateInput" << endl;
	    }else
		cout << "ERROR, impossible to create automateInput thread" << endl;

	    pthread_join(clientGuiOutput, NULL);
	    cout << "End of event thread clientGuiOutput" << endl;
	}else
	    cout << "ERROR, impossible to create clientGuiOutput thread" << endl;
	  
	pthread_join(clientGuiInput, NULL);
	cout << "End of event thread clientGuiInput" << endl;
    }else
	cout << "ERROR, impossible to create clientGuiInput thread" << endl;


    delete prodConsCommon;
    delete prodConsOutputAutomate;
    delete prodConsOutputClientGui;



    ///////////////////////////////
    // Game initialisation
    ///////////////////////////////


    // Pile of the targets of the players
    PileTarget stopCards = PileTarget();
    // this will contain the stop cards of the players
    Card playersStops[nbrPlayer];

    // we scan all players registered for the game
    for (int i = 0; i < nbrPlayer; i++){
        // we pick a stop card
        playersStops[i] = stopCards.take();
        // then we set the players' tiles one by one
        for (int j = 0; j < HAND_SIZE; j++){
            players[i].hand[j] = Tile(pile.take(),i);
        }
    }



    // we chose the first player

    currentPlayer = rand() % nbrPlayer;


    ///////////////////////////////
    // here starts the referee


    Pack readPack;
    int readPlayer;


    /*while(!won){

        readPack = players[currentPlayer].circularQueue.consume();
        idPack << readPack;
        readPlayer << readPack;
        // if the pack was sent by the current player we call the appropriate function to validate or not the move, else we do nothing and wait for the write player to communicate.
        switch (readPack.idPack) {
            case STARTTRAVEL :
                travelstarted((StartTravel*)&readPack, currentPlayer, gameBoard);
                break;
            case PLAYTRAVEL :
                travelplayed((PlayTravel*)&readPack, currentPlayer, gameBoard);
                break;
            case STOPTRAVEL :
                travelstopped((StopTravel*)&readPack, currentPlayer, gameBoard);
                break;
            case PLAYTILE :
                tileplayed((PlayTile*)&readPack, currentPlayer, gameBoard, players);
                break;
            case PILEWHENTRAVEL :
                pilewhentravel((PileWhenTravel*)&readPack, currentPlayer, gameBoard);
                break;
            default :   //error, we do nothing
                break;
            }
            readPlayer << readPack;

        }


	}*/

}
