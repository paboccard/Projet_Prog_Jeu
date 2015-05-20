#include "Server.h"
#include "Moteur.h"
#include <cstdlib>


void thread(ProdCons<string> queueIn, ProdCons<string> queueOut){
}


int main(int argc, char **argv){
    int nbrPlayer;
    int currentPlayer;
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

    bool won = false;
    Pack readPack, answerPack;
    int readPlayer, nbrTilesPlayed;
    protocol idPack;


    while(!won){

        readPack players[currentPlayer].circularQueue.consume();
        idPack << readPack;
        readPlayer << readPack;
        // if the pack was sent by the current player we read it, else we do nothing and wait for the write player to communicate.
        if (readPlayer == currentPlayer){
            switch (idPack) {
                case 0 :    // StartTravel
                    nbrTilesPlayed << readPack;
                    Tiles[nbrTilesPlayed] travel;
                    while (int i = 0; i< nbrTilesPlayed; i++){
                        travel[i] << readPack;
                    }

                case 1 :    // PlayTravel
                case 2 :    // StopTravel
                case 3 :    // PlayTile
                default :   //error, we do nothing
            }
            readPlayer << readPack;

        }


    }

}
