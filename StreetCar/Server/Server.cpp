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
//#include "../Shared/PileWhenTravel.h"
#include "../Shared/PlayedTile.h"
#include "CircularQueueClient.h"

#include "PlayerServer.h"
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <iostream>
#include <string.h>
#include <arpa/inet.h>

using namespace std;


#define NB_TILE_MAX 2

// sends an error pack to the specified error with the error descriptor
void sendError(int player, error_pack error){
    // TO-DO send error to the player
}
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
    Pack* aswerPack;

    // TO-DO checking validation

    // TO-DO throw validation and update of the board

}

// handling of a STOPTRAVEL pack
void travelstopped(StopTravel *readPack, int currentPlayer, Board gameBoard){

    // TO-DO checking validation

    // TO-DO throw validation and update of the board
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

    for (int i = 0; i < NB_TILE_MAX; i++){
        // We check if it is a replace move
        Square boardSquare = gameBoard.get(playersHand[idxhand[i]].coordinates.x, playersHand[idxhand[i]].coordinates.y);
        if (boardSquare.isEmpty()){
            // this is not a replace move
            if (gameBoard.putPossible(playersHand[idxhand[i]].coordinates.x, playersHand[idxhand[i]].coordinates.y, playersHand[idxhand[i]])){
                // if the tile can be played we check if it is next to a stop
                Stop* stop = gameBoard.nextToStop(playersHand[idxhand[i]].coordinates.x, playersHand[idxhand[i]].coordinates.y) ;
                if( stop != NULL){
                    // stop represent the adjacent stop, if there is no Tile associated to it, we associate the stop to the pointer of the tile on the board and the tile is set as a stop tile
                    if (!(stop->isLinked())){
                        playersHand[idxhand[i]].isStop = true;
                        stop->linked = (Tile *)gameBoard.getPointer(playersHand[idxhand[i]].coordinates.x, playersHand[idxhand[i]].coordinates.y);
                    }
                }

            } else {
                // the tile can't be set here we get an impossible play error
                sendError(currentPlayer, IMPOSSIBLE_PLAY);
                return;
            }
        } else {
            // this is a replace move, we check if you can put the card here
            Square squareTmp = gameBoard.get(playersHand[idxhand[i]].coordinates.x, playersHand[idxhand[i]].coordinates.y);
            Tile tileTmp;
            if (squareTmp.isTile()){
                tileTmp = Tile(squareTmp.type, 0);
            } else {
                sendError(currentPlayer, IMPOSSIBLE_PLAY);
                return;
            }


            if (playersHand[idxhand[i]].change(tileTmp)){
                // then we check if we can put it
                if (!gameBoard.putPossible(playersHand[idxhand[i]].coordinates.x, playersHand[idxhand[i]].coordinates.y, playersHand[idxhand[i]])){

                    // the tile can't be set here we get an impossible play error
                    sendError(currentPlayer, IMPOSSIBLE_PLAY);
                    return;
                }

            }

            // throw validation and update of the board
        }
    }
    vector<Tile> played;
    // if the tests above suceed, we update the local board and hand
    for (int i = 0; i<NB_TILE_MAX; i++) {
        played[i] = playersHand[idxhand[i]];
        gameBoard.set(played[i].coordinates.x, played[i].coordinates.y, played[i]);
    }

    // creation of a responce pack
    PlayedTile playedTile = PlayedTile(currentPlayer, played);
    for (int i = 0; i < players.size(); i++){
        players[i].circularQueue->produce(&playedTile);
    }
}
// handling of a PILEWHENTRAVEL pack
void pilewhentravel(PileWhenTravel *readPack, int currentPlayer, Board gameBoard){

    // TO-DO checking validation

    // throw validation and update of the board
}



int main(int argc, char **argv){
    int nbrPlayer = 1;
    int currentPlayer;
    int lastTravelLength = 0;
    bool start = false;
    bool won = false;
    vector<PlayerServer> players;

    int sockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;

    // creation of the Pile
    Pile pile = Pile();
    // creation of the Board
    Board gameBoard = Board();

    //    while(!start){
    // TO-DO : initialization of the game
    // must fill players with a vector of PlayerServer containing the list of Player + a ProdCons associated to him

    // wait for connexions, the first in is the host then new players for online game, else the gui for local games with all human players then the computers connect one by one
    // when the host (online game) or the gui (local game) sends the message to start, set start to true and this is the end of the initialization.

    //create a socket
    //socket(int domain, int type, int protocol)
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        cout << "ERROR opening socket" << endl;
        exit(0);
    }

    //clear adresse structure
    bzero((char *)&serv_addr, sizeof(serv_addr));

    //num of port
    portno = 8080;

    //sertup the host_addr structure for use in bind call
    //server byte order
    serv_addr.sin_family = AF_INET;

    //automatically be filled with current host's IP adresse
    serv_addr.sin_port = htons(portno);

    /* bind(int fd, struct sockaddr *local_addr, socklen_t addr_length)
       bind() passes file descriptor, the address structure,
       and the length of the address structure
       This bind() call will bind  the socket to the current IP address on port, portno*/
    if (bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) <0)
        cout << "ERROR on binding" << endl;

    // This listen() call tells the socket to listen to the incoming connections.
    // The listen() function places all incoming connection into a backlog queue
    // until accept() call accepts the connection.
    // Here, we set the maximum size for the backlog queue to 5.
    listen(sockfd,5);

    ProdCons<Pack*> *prodConsCommon = new ProdCons<Pack*>();
    pthread_t client[5];
    ProdCons<Pack*> *prodConsOutputClient[5];

    for (int i = 0; i<5; i++){
        prodConsOutputClient[i] = new ProdCons<Pack*>();
        ParamThread paramThread = {prodConsOutputClient[i],prodConsCommon,sockfd,&serv_addr, &cli_addr};
        if (pthread_create(&client[i], NULL, clientOutputHandler,(void *)(&paramThread))==0){
            cout << "End of event thread client " << i << endl;
        }else
            cout << "ERROR, impossible to create client " << i << endl;
    }
    cout << endl;

    Pack * pack;
    while (!start){
        pack = prodConsCommon->consume();
        switch(pack->idPack){
        case IWANTPLAY:
            break;
        case STARTGAME:
            start = true;
            break;
        case CIRCULARQUEUECLIENT:
            CircularQueueClient *c = (CircularQueueClient*)pack;
            PlayerServer ps = PlayerServer(c->prodConsClient);
            players.push_back(ps);
            nbrPlayer++;
            break;
        }
    }

    //    }

    ///////////////////////////////
    // Game initialisation
    ///////////////////////////////


    // Pile of the targets of the players
    PileTarget stopCards = PileTarget();


    // this is the hands we will sand for the pack
    vector<vector<Tile> > hands(nbrPlayer, vector<Tile>(HAND_SIZE));
    // this will contain the stop cards of the players
    vector <GoalPlayer> goals(nbrPlayer);

    // we will pick the lines :
    vector<int> lines;
    for (int i = 0; i < NBR_LINES; i++)
        lines.push_back(i+1);

    // we scan all players registered for the game
    for (int i = 0; i < nbrPlayer; i++){
        // we pick a stop card
        goals[i].stop = stopCards.take();
        // we pick a line for the player i
        goals[i].line = lines[rand()%lines.size()];
        lines.erase(lines.begin() + (goals[i].line - 1));
        // then we set the players' tiles one by one
        for (int j = 0; j < HAND_SIZE; j++){
            players[i].hand[j] = Tile(pile.take(),i);
            hands[i][j] = players[i].hand[j];
        }
    }
    // we chose the first player
    currentPlayer = rand() % nbrPlayer;

    InitGame initGame = InitGame(hands, pile, currentPlayer, goals);

    ///////////////////////////////
    // here starts the referee
    ///////////////////////////////

    int readPlayer;


    while(!won){
        Pack* readPack = players[currentPlayer].circularQueue->consume();

        // if the pack was sent by the current player we call the appropriate function to validate or not the move, else we do nothing and wait for the write player to communicate.
        switch (readPack->idPack) {
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


        close(sockfd);

    }

    for (int i = 0; i<5; i++)
        pthread_join(client[i], NULL);

    delete prodConsCommon;
    for (int i=0; i<5; i++)
        delete prodConsOutputClient[i];

    return 0;
}
