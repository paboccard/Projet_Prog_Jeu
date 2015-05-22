#include "../Shared/Packs.h"
#include "../Shared/Board.h"
#include "../Shared/StartTravel.h"
#include "../Shared/PlayTravel.h"
#include "../Shared/StopTravel.h"
#include "../Shared/PlayTile.h"
#include "../Shared/Pile.h"
#include "../Shared/PileWhenTravel.h"
//#include "../Shared/PileWhenTravel.h"
#include "PlayerServer.h"
#include <cstdlib>
using namespace std;

// TO-DO find where to save the travels of the trains of each player.






Pile pile;
vector<PlayerServer> players;

// handling of a STARTTRAVEL pack
void travelstarted(StartTravel *readPack, int currentPlayer, Board gameBoard){
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
}

// handling of a PLAYTRAVEL pack
void travelplayed(PlayTravel *readPack, int currentPlayer, Board gameBoard){
    Pack aswerPack;

    // TO-DO checking validation

    // TO-DO throw validation and update of the board

}

// handling of a STOPTRAVEL pack
void travelstopped(StopTravel *readPack, int currentPlayer, Board gameBoard){

    // TO-DO checking validation

    // TO-DO throw validation and update of the board
}

// handling of a PLAYTILE pack
void tileplayed(PlayTile *readPack, int currentPlayer, Board gameBoard){
    int idxhand1 = readPack->idxHand[0];
    int idxhand2 = readPack->idxHand[0];
    Tile playerHand[5] = players[currentPlayer].hand;
    // TO-DO checking validation

    // We check if it is a replace move
    Square boardSquare = gameBoard.get(playerHand[idxhand1].coordinates.x, playerHand[idxhand1].coordinates.y);
    if (boardSquare.isEmpty()){
        // this is not a replace move

    }

    // throw validation and update of the board
}

// handling of a PILEWHENTRAVEL pack
void pilewhentravel(PileWhenTravel *readPack, int currentPlayer, Board gameBoard){

    // TO-DO checking validation

    // throw validation and update of the board
}


// sends an error pack to the specified error with the error descriptor
void sendError(int player, error_pack error){
    // TO-DO send error to the player
}

int main(int argc, char **argv){
    int nbrPlayer;
    int currentPlayer;
    int lastTravelLength = 0;
    bool start = false;
    bool won = false;


    // creation of the Pile
    Pile pile = Pile();
    // creation of the Board
    Board gameBoard = Board();

    while(!start){
    // TO-DO : initialization of the game
        // must fill players with a vector of PlayerServer containing the list of Player + a ProdCons associated to him

        // wait for connexions, the first in is the host then new players for online game, else the gui for local games with all human players then the computers connect one by one
        // when the host (online game) or the gui (local game) sends the message to start, set start to true and this is the end of the initialization.
    }

    ///////////////////////////////
    // Game initialisation
    ///////////////////////////////


    // we scan all players registered for the game
    for (int i = 0; i < nbrPlayer; i++){
        // we set the players' tiles one by one
        for (int j = 0; j < 5; j++){
            players[i].hand[j] = Tile(pile.take(),i);
        }
    }

    // TO-DO : pick a stop card

    // we chose the first player

    currentPlayer = rand() % nbrPlayer;


    ///////////////////////////////
    // here starts the referee
    ///////////////////////////////

    int readPlayer;


    while(!won){

        Pack readPack = players[currentPlayer].circularQueue->consume();

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
                tileplayed((PlayTile*)&readPack, currentPlayer, gameBoard);
                break;
            case PILEWHENTRAVEL :
                pilewhentravel((PileWhenTravel*)&readPack, currentPlayer, gameBoard);
                break;
            default :   //error, we do nothing
            break;
            }

    }

}
