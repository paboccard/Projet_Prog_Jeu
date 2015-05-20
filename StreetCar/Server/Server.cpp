#include "Server.h"
#include "Moteur.h"
#include <cstdlib>


void thread(ProdCons<string> queueIn, ProdCons<string> queueOut){
}


int main(int argc, char **argv){
    int nbrPlayer;
    int currentPlayer;
    bool start = false;
    bool won = false;

    vector<PlayerServer> players;


    currentPlayer = rand() % nbrPlayer;


    while(!start){
    // TO-DO : initialization of the game
        // must fill players with a vector of PlayerServer containing the list of Player + a ProdCons associated to him

        // wait for connexions, the first in is the host then new players for online game, else the gui for local games with all human players then the computers connect one by one
        // when the host (online game) or the gui (local game) sends the message to start, set start to true and this is the end of the initialization.
    }

    while(!won){
    // here starts the referee
    }

}
