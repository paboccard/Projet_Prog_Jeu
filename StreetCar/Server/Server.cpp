#include "Server.h"
#include "Moteur.h"
#include "../Shared/Packs.h"
#include "PlayerServer.h"
#include <cstdlib>

// TO-DO find where to save the travels of the trains of each player.

int nbrPlayer;
int currentPlayer;
int lastTravelLength = 0;
bool won = false;
Board gameBoard;

void thread(ProdCond<string> queueIn, ProdCond<string> queueOut){
}

// handling of a STARTTRAVEL pack
void travelstarted(Pack readPack){
    Pack answerPack;


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



}

// handling of a PLAYTRAVEL pack
void travelplayed(Pack readPack){
    Pack aswerPack;

    // TO-DO checking validation

    // TO-DO throw validation and update of the board

}

// handling of a STOPTRAVEL pack
void travelstopped(Pack readPack){

    // TO-DO checking validation

    // TO-DO throw validation and update of the board
}

// handling of a PLAYTILE pack
void tileplayed(Pack readPack){

    // TO-DO checking validation

    // throw validation and update of the board
}

// handling of a PILEWHENTRAVEL pack
void pilewhentravel(readPack){

    // TO-DO checking validation

    // throw validation and update of the board
}


// sends an error pack to the specified error with the error descriptor
void sendError(int player, error_pack error){
    // TO-DO send error to the player
}

int main(int argc, char **argv){

    bool start = false;


    vector<PlayerServer> players;


    currentPlayer = rand() % nbrPlayer;


    while(!start){
    // TO-DO : initialization of the game
        // must fill players with a vector of PlayerServer containing the list of Player + a ProdCons associated to him

        // wait for connexions, the first in is the host then new players for online game, else the gui for local games with all human players then the computers connect one by one
        // when the host (online game) or the gui (local game) sends the message to start, set start to true and this is the end of the initialization.
    }
    gameBoard = new Board();

    // here starts the referee


    Pack readPack;
    int readPlayer;


    while(!won){

        readPack players[currentPlayer].circularQueue.consume();

        // if the pack was sent by the current player we call the appropriate function to validate or not the move, else we do nothing and wait for the write player to communicate.
        if (readPack.idPlayer == currentPlayer){
            switch (readPack.idPack) {
                case STARTTRAVEL :
                    travelstarted(readPack);
                case PLAYTRAVEL :
                    travelplayed(readPack);
                case STOPTRAVEL :
                    travelstopped(readPack);
                case PLAYTILE :
                    tileplayed(readPack);
                case PILEWHENTRAVEL :
                    pilewhentravel(readPack);
                default :   //error, we do nothing
            }


        }


    }

}
