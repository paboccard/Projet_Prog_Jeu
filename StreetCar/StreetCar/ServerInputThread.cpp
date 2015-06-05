#include "ServerInputThread.h"
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
#include "../Shared/Won.h"
#include "../Shared/PilePlayer.h"
#include "../Shared/NewPlayerAdd.h"
#include "../Shared/Pack.h"
#include "../Shared/Debug.h"
#include "../Shared/YourIdPlayer.h"
#include "../Shared/Goal.h"
#include "errno.h"


#include <QDebug>

using namespace std;

ServerInputThread::ServerInputThread(QObject *parent) :
    QThread(parent)
{
    sockfd = 0;
}

void ServerInputThread::run()
{
    cout << "Input thread start" << endl;
    stringstream ss;
    char buffer[MAX_PACKET_SIZE];
    int n;

    bool end = false;
    while (!end) {
	Pack *pack = NULL;
	int packetSize;
        recv(sockfd, (char*)&packetSize, sizeof(int), MSG_WAITALL);
	packetSize = ntohl(packetSize);
        n = recv(sockfd,buffer,packetSize,MSG_WAITALL);

        if (n > 0) {

	    //cout << "reading on socket " << n << " " << buffer << endl;
	    buffer[n] = '\0';
	    ss.str(string()); //to clear the stringstream
	    ss.clear();

	    ss << buffer;
	    int i;
	    ss >> i;

	    switch((packs)i){
	    case STARTTRAVEL:
		{
		    StartTravel* tmp = new StartTravel();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;
	    case PLAYTRAVEL:
		{
		    PlayTravel* tmp = new PlayTravel();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;
	    case STOPTRAVEL:
		{
		    StopTravel* tmp = new StopTravel();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;
	    case PLAYTILE:
		{
		    PlayTile* tmp = new PlayTile();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;
	    case PILEWHENTRAVEL:
		{
		    PileWhenTravel* tmp = new PileWhenTravel();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;
	    case IWANTPLAY:
		{
		    IWantPlay* tmp = new IWantPlay();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;
	    case STARTGAME:
		{
		    StartGame* tmp = new StartGame();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;
	    case CREATEGAME:
		{
		    CreateGame* tmp = new CreateGame();
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
	    case YOURIDPLAYER:
		{
		    YourIdPlayer* tmp = new YourIdPlayer();
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
	    case GOAL:
		{
		    Goal* tmp = new Goal();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;
	    default:
		qDebug() << "ERROR packet read is undefined " << (packs)i;
		break;
	    }
	    emit receive(pack);
	}
	else {
	    emit receive(new Validation(DISCONNECTED));
	    qDebug() << "ERROR reading from socket input thread";
	    end = true;
	}
    }
}
