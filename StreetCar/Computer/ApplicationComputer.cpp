#include "Computer.h"
#include "../Shared/ProdCons.h"
#include "../Shared/ParamThreadClient.h"
#include "../Shared/IWantPlay.h"
#include "../Shared/InitGame.h"
#include "../Shared/NewPlayerAdd.h"
#include "../Shared/YourIdPlayer.h"
#include "../Shared/PlayedTile.h"
#include "../Shared/PlayTile.h"
#include "../Shared/PilePlayer.h"
#include "serverHandler.h"
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>

using namespace std;

int main(int argc, char *argv[]){

    struct sockaddr_in serv_addr;
    struct hostent *server = NULL;
    int portno = 8080;
    int sockfd;
    Computer *computer;
    int idPlayer = -1;
    int currentPlayer;
    Pack* readPack = NULL;
    bool isFinish = false;
    bool start = false;
 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
	cout << "ERROR opening socket" << endl;
	return false;
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
	cout << "ERROR, no such host " << endl;
	exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));//reset addr
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
    serv_addr.sin_port = htons(portno);

    //Adress by IP
    serv_addr.sin_addr.s_addr = inet_addr("152.77.82.244");
    //bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    cout << "start to connect to the server " << sockfd << endl;
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
	cout << "ERROR connecting " << endl;
	return false;
    }
    
    cout << "Connected to the server" << endl;

    pthread_t serverThreadOutput;
    pthread_t serverThreadInput;
    ProdCons<Pack*> *prodConsOutput;
    ProdCons<Pack*> *prodConsInput;
    prodConsOutput = new ProdCons<Pack*>();
    prodConsInput = new ProdCons<Pack*>();
    ParamThreadComputer paramThreadOutput = {prodConsOutput,sockfd};
    ParamThreadComputer paramThreadInput = {prodConsInput,sockfd};
    if (pthread_create(&serverThreadOutput, NULL, serverOutputHandler,(void *)(&paramThreadOutput))==0){
	cout << "End of event thread server Output" << endl;
    }else
	cout << "ERROR, impossible to create server " << endl;
    if (pthread_create(&serverThreadInput, NULL, serverInputHandler,(void *)(&paramThreadInput))==0){
	cout << "End of event thread server Input" << endl;
    }else
	cout << "ERROR, impossible to create server " << endl;

    while (idPlayer == -1){
	Profile profile = Profile((string)argv[1],atoi(argv[2]));
	IWantPlay *p = new IWantPlay(profile);
	prodConsOutput->produce(p);
	readPack = prodConsInput->consume();
	if (readPack->idPack == YOURIDPLAYER){
	    YourIdPlayer *myId = (YourIdPlayer*)readPack;
	    idPlayer = myId->idPlayer;
	}
	delete readPack;
    }

    while(!start){
	readPack = prodConsInput->consume();
	if (readPack->idPack == INITGAME){
	    InitGame *init = (InitGame*)readPack;
	    computer = new Computer(init->hands, idPlayer, init->goalPlayer);
	    currentPlayer = init->idFirstPlayer;
	    start = true;
	}
	delete readPack;
    }
    while(!isFinish){
	if (currentPlayer == idPlayer){
	    //TODO return PlayTile(...);
	    PlayTile pt = computer->easy();
 	    prodConsOutput->produce(&pt);
	}
	else{
	    readPack = prodConsInput->consume();
	    switch(readPack->idPack){
	    case PLAYEDTILE:
		{
		    PlayedTile *pt = (PlayedTile*)readPack;
		    //TODO modif board
		}
		break;
	    case PILEPLAYER:
		{
		    PilePlayer* pp = (PilePlayer*)readPack;
		    currentPlayer = pp->idNextPlayer;
		    //for (unsigned int i = 0; i < pp->tilesPiled.size(); i++)
			
		    //TODO modif pile & hand last player
		}
		break;
	    default:
		break;
	    }
	    delete readPack;
	}
    }


    close(sockfd);
    return 0;
}
