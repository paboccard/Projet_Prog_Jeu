#include "../Shared/Packs.h"
#include "../Shared/Pack.h"
#include "PlayerServer.h"
#include <cstdlib>
#include <pthread.h>
#include "clientGuiHandler.h"

using namespace std;

int nbrPlayer;
int currentPlayer;
bool won = false;

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
    Board gameBoard;

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



    //}

    // here starts the referee


    Pack readPack;
    int readPlayer;


    /*while(!won){

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


	}*/

}
