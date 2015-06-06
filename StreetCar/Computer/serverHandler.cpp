#include "serverHandler.h"
#include <fstream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sstream>
#include "../Shared/Tile.h"
#include "../Shared/Utils.h"
#include <pthread.h>
#include "../Shared/ParamThreadClient.h"
#include "../Shared/StartTravel.h"
#include "../Shared/PlayTravel.h"
#include "../Shared/StopTravel.h"
#include "../Shared/PlayTile.h"
#include "../Shared/PileWhenTravel.h"
#include "../Shared/IWantPlay.h"
#include "../Shared/StartGame.h"
#include "../Shared/CreateGame.h"
#include "../Shared/InitGame.h"
#include "../Shared/PlayedTile.h"
#include "../Shared/PlayedTravel.h"
#include "../Shared/StartedTravel.h"
#include "../Shared/StoppedTravel.h"
#include "../Shared/Validation.h"
#include "../Shared/YourIdPlayer.h"
#include "../Shared/Won.h"
#include "../Shared/PilePlayer.h"
#include "../Shared/NewPlayerAdd.h"
#include "../Shared/Pack.h"
#include "../Shared/Debug.h"
#include "../Shared/Quit.h"

using namespace std;

void *serverOutputHandler(void* argv){

    //recover params for the thread
    ParamThreadComputer *param = (ParamThreadComputer*)argv;

    ProdCons<Pack*> *prodConsOutput = param->prodCons;
    int sockfd = param->sockfd;
    int n;

    cout << "Event thread serverOutputHandler started successful : " << pthread_self() << endl;

    bool isFinish = false;
    Pack *readPack;

    while (!isFinish){
	readPack = prodConsOutput->consume();

	stringstream ss;
	ss << *readPack;
	ss.seekg(0, ios::end);
	int size = ss.tellg(); //size contain the size (in bytes) of the string
	
	cout << "message -------------- " << ss.str() << endl;
	int g = htonl(size);
	n = write(sockfd, (const char*)&g, sizeof(int));
	n = write(sockfd, ss.str().c_str(), size);
	cout << "write on network " << endl;
	    
	if (n < 0) 
	    cout << "ERROR writing from socket" << endl;
	delete readPack;
    }

    close(sockfd);

    return 0;

}
 
void *serverInputHandler(void* argv){

    //recover params for the thread
    cout << "Computer input start successful : " << pthread_self() << endl;
    ParamThreadComputer *param = (ParamThreadComputer*)argv;


    ProdCons<Pack*> *prodConsInput = param->prodCons;
    int newsockfd = param->sockfd;

    stringstream ss;
    char buffer[MAX_PACKET_SIZE];
    int n;
    bool isFinish = false;

    while (!isFinish){
	Pack *pack = new Pack();
	//bzero(buffer,MAX_PACKET_SIZE);
	cout << "POC 1 " << endl;
	int a ;
	n = recv(newsockfd,(char*)&a,sizeof(int),MSG_WAITALL);
	cout << "POC 2 " << endl;
	a = ntohl(a);
	cout << "receive int a = " << a << endl;
	n = recv(newsockfd,buffer,a,MSG_WAITALL);
	if (n > 0) {

	    cout << "reading on socket " << n << " " << buffer << endl;
	    buffer[n] = '\0';
	    ss.str(string()); //to clear the stringstream 
	    ss.clear();
			
	    ss << buffer;
	    
	    int i;
	    ss >> i;
	    cout << " * * ** * * * * * numero i = " << i << endl;
	    switch((packs)i){ 
	    case YOURIDPLAYER:
		{
		    YourIdPlayer* tmp = new YourIdPlayer();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;

	    case DEBUG:
		{
		    Debug* tmp = new Debug();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;
	    case INITGAME:
		{
		    InitGame* tmp = new InitGame();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;
	    case PLAYEDTILE:
		{
		    PlayedTile* tmp = new PlayedTile();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;
	    case PLAYEDTRAVEL:
		{
		    PlayedTravel* tmp = new PlayedTravel();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;
	    case STARTEDTRAVEL:
		{
		    StartedTravel* tmp = new StartedTravel();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;
	    case STOPPEDTRAVEL:
		{
		    StoppedTravel* tmp = new StoppedTravel();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;
	    case VALIDATION:
		{
		    Validation* tmp = new Validation();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;
	    case WON:
		{
		    Won* tmp = new Won();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;
	    case PILEPLAYER:
		{
		    PilePlayer* tmp = new PilePlayer();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;
	    case NEWPLAYERADD:
		{
		    NewPlayerAdd* tmp = new NewPlayerAdd();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;
	    case QUIT:
		{
		    Quit* tmp = new Quit();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;

	    default:
		cout << "deserialisable error" << endl;
		break;
	    }
	    cout << "this is pack : "<< *pack << endl;
	    prodConsInput->produce(pack);
	}
	else {
	    cout << "ERROR reading from socket" << endl;
	    isFinish = true;
	    return 0;
	}
    }
    close(newsockfd);
    return 0;
}
