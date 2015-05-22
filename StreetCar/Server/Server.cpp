#include "Server.h"
#include "Moteur.h"
#include "../Shared/Packs.h"
#include "PlayerServer.h"
#include <cstdlib>

int nbrPlayer;
int currentPlayer;
bool won = false;
Board gameBoard;

void thread(ProdCons<string> queueIn, ProdCons<string> queueOut){
}

// handling of a STARTTRAVEL pack
void travelstarted(Pack readPack){
    Pack answerPack;

    // TO-DO checking validation

    // TO-DO throw validation
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
void tileplayed(Pack readPack){

    // TO-DO reading the pack

    // TO-DO checking validation

    // TO-DO throw validation
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

    // here starts the referee


    Pack readPack;
    int readPlayer;


    while(!won){

        readPack = players[currentPlayer].circularQueue.consume();
        idPack << readPack;
        readPlayer << readPack;
        // if the pack was sent by the current player we call the appropriate function to validate or not the move, else we do nothing and wait for the write player to communicate.
        if (readPlayer == currentPlayer){
            switch (readPack.idPack) {
                case 0 :    // StartTravel
                    travelstarted(readPack);
                case 1 :    // PlayTravel
                    travelplayed(readPack);
                case 2 :    // StopTravel
                    travelstopped(readPack);
                case 3 :    // PlayTile
                    tileplayed(readPack);
                default :   //error, we do nothing
            }
            readPlayer << readPack;

        }


    }

}
