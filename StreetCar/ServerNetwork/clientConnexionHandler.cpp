#include "clientConnexionHandler.h"
#include "../Shared/CreateGameNetwork.h"
#include "../Shared/IWantPlayNetwork.h"
#include "../Shared/RefreshGamesNetwork.h"
#include "../Shared/ResponseRefresh.h"
#include "../Shared/Debug.h"
#include "../Shared/Launch.h"
#include "../Shared/Quit.h"
#include "../Shared/StartGame.h"
#include <cerrno>

using namespace std;

void *clientOutputConnexionHandler(void* argv){

    //recover params for the thread
    ParamThread *param = (ParamThread*)argv;

    ProdCons<Pack*> *prodConsOutput = param->prodConsClient;
    ProdCons<Pack*> *prodConsInput = param->prodConsCommon;
    int sockfd = param->sockfd;
    struct sockaddr_in serv_addr = *param->serv_addr;
    struct sockaddr_in cli_addr = *param->cli_addr;

    //    cout << "SN: Event thread client1Handler started successful : " << pthread_self() << endl;

    int newsockfd;
    socklen_t clilen;
    stringstream buffer2;
    char buffer[256];
    int n;
    bool isFinish = false;
    Pack *readPack;
    

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0){ 
	cout << "S: ERROR on accept" << endl;
	exit(0);
    }

    //cout << "SN: Thread which ACCEPT : " << pthread_self() << endl;

    // CircularQueueClient *circular = new CircularQueueClient(prodConsOutput);
    // prodConsInput->produce(circular);

    cout << "SN: server: got connection from " << inet_ntoa(cli_addr.sin_addr) << " port " << ntohs(cli_addr.sin_port) << endl ;

    //create the listener thread
    pthread_t client;
    ParamThread paramInput = {prodConsOutput,prodConsInput,newsockfd,&serv_addr,&cli_addr};

    if (pthread_create(&client, NULL, clientInputConnexionHandler,(void *)(&paramInput))==0){
    }else
	cout << "SN: ERROR, impossible to create clientInput " << endl;


    while (!isFinish){
	readPack = prodConsOutput->consume();
	
	if (readPack->idPack == QUIT){
	  cout << "SN: ----------------------- I DELETE THE SOCKET " << endl;
	  Quit* q = (Quit*)readPack;
	  prodConsInput->produce(new Launch(q->numGame));
	  cout << "send cancel to input thread " << endl;
	  //close(newsockfd);
	  pthread_cancel(client);
	  delete readPack;
	  return 0;
	}

	stringstream ss;
	ss << *readPack;
	ss.seekg(0, ios::end);
	int size = ss.tellg(); //size contain the size (in bytes) of the string
	
	cout << "SIZE message " << size << endl;
	cout << "Type de Message : " << readPack->toString() << endl;
	cout << "SN: message -------------- " << ss.str() << endl;
	
	int g = htonl(size);
	if ((n=write(newsockfd, (const char*)&g, sizeof(int)))<0){
	  cout << "Something went wrong! errno " << errno << ": ";
	  cout << strerror(errno) << endl;
	}
	
	if ((n = write(newsockfd, ss.str().c_str(), size))<0){
	  cout << "Something went wrong! errno " << errno << ": ";
	  cout << strerror(errno) << endl;
	}
	if (n < 0) 
	    cout << "SN: ERROR writing from socket" << endl;
	    //cout << "SN: write on network " << endl	 

	delete readPack;
    }

    cout << "end of thread clientConnexionHandler" << endl;
    close(newsockfd);

    return 0;

}

void *clientInputConnexionHandler(void* argv){

    //recover params for the thread
    cout << "SN: Clien input start successful : " << pthread_self() << endl;
    ParamThread *param = (ParamThread*)argv;
    
    ProdCons<Pack*> *prodConsOutput = param->prodConsClient;
    ProdCons<Pack*> *prodConsInput = param->prodConsCommon;
    int newsockfd = param->sockfd;
    struct sockaddr_in serv_addr = *param->serv_addr;
    struct sockaddr_in cli_addr = *param->cli_addr;

    stringstream ss;
    char buffer[MAX_PACKET_SIZE];
    int n;
    bool isFinish = false;

    while (!isFinish){
	Pack *pack = new Pack();
	bzero(buffer,MAX_PACKET_SIZE);
	int a ;
	n = recv(newsockfd,(char*)&a,sizeof(int),MSG_WAITALL);
	a = ntohl(a);
	cout << "SN: receive int a = " << a << endl;
	n = recv(newsockfd,buffer,a,MSG_WAITALL);
	if (n > 0) {

	    cout << "SN: reading on socket " << n << " " << buffer << endl;
	    buffer[n] = '\0';
	    ss.str(string()); //to clear the stringstream 
	    ss.clear();
			
	    ss << buffer;
	    
	    int i;
	    ss >> i;
	    switch((packs)i){
	    case CREATEGAMENETWORK:
		{
		    CreateGameNetwork* tmp = new CreateGameNetwork();
		    ss >> *tmp;
		    tmp->prodConsClient = prodConsOutput;
		    pack = tmp;
		    //isFinish = true;
		}
		break;
	    case IWANTPLAYNETWORK:
		{
		    IWantPlayNetwork* tmp = new IWantPlayNetwork();
		    ss >> *tmp;
		    tmp->prodConsClient = prodConsOutput;
		    cout << " ****** my prodCons " << tmp->prodConsClient << endl;
		    tmp->sockfd = newsockfd;
		    tmp->serv_addr = serv_addr;
		    tmp->cli_addr = cli_addr;
		    pack = tmp;
		}
		break;
	    case REFRESHGAMESNETWORK:
		{
		    RefreshGamesNetwork* tmp = new RefreshGamesNetwork();
		    ss >> *tmp;
		    tmp->prodConsClient = prodConsOutput;
		    pack = tmp;
		}
		break;
	    case STARTGAMENETWORK:
		{
		    StartGameNetwork* tmp = new StartGameNetwork();
		    ss >> *tmp;
		    pack = tmp;
		}
		break;
	    default:
		cout << "SN: deserialisable error" << endl;
		break;
	    }
	    cout << "SN: this is pack : "<< *pack  << " - type " << pack->toString() << endl;
	    prodConsInput->produce(pack);
	}
	else {
	    cout << "SN: ERROR reading from socket" << endl;
	    isFinish = true;
	    return 0;
	}
    }
    cout << "end of thread clientConnexionHandler Input " << endl;
    close(newsockfd);
    return 0;
}
