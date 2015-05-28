//#include "PlayedTravel.h"
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
#include "../Shared/PlayedTile.h"
#include "../Shared/Utils.h"
#include "../Shared/Debug.h"
#include <pthread.h>
#include "clientGuiHandler.h"
#include "ParamThreadClient.h"
#include "../Shared/Pack.h"
#include "CircularQueueClient.h"

using namespace std;

void *clientOutputHandler(void* argv){

    //recover params for the thread
    ParamThread *param = (ParamThread*)argv;

    ProdCons<Pack*> *prodConsClient = param->prodConsClient;
    ProdCons<Pack*> *prodConsCommon = param->prodConsCommon;
    int sockfd = param->sockfd;
    struct sockaddr_in serv_addr = *param->serv_addr;
    struct sockaddr_in cli_addr = *param->cli_addr;

    cout << "Event thread client1Handler started successful : " << pthread_self() << endl;

    int newsockfd;
    socklen_t clilen;
    stringstream buffer2;
    char buffer[256];
    int n;
    bool isFinish = false;
    Pack *readPack;
    //The accept() call actually accepts an incoming connection
    clilen = sizeof(cli_addr);

    // This accept() function will write the connecting client's address info 
    // into the the address structure and the size of that structure is clilen.
    // The accept() returns a new socket file descriptor for the accepted connection.
    // So, the original socket file descriptor can continue to be used 
    // for accepting new connections while the new socker file descriptor is used for
    // communicating with the connected client.
    newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0){ 
	cout << "ERROR on accept" << endl;
	exit(0);
    }
    CircularQueueClient *circular = new CircularQueueClient(prodConsClient);
    prodConsCommon->produce(circular);

    cout << "server: got connection from " << inet_ntoa(cli_addr.sin_addr) << " port " << ntohs(cli_addr.sin_port) << endl ;

    //create the listener thread
    pthread_t client;
    ParamThreadInput paramInput = {prodConsCommon,newsockfd,&serv_addr,&cli_addr};

    cout << "sock 1 : " << newsockfd << endl;
    if (pthread_create(&client, NULL, clientInputHandler,(void *)(&paramInput))==0){
    }else
	cout << "ERROR, impossible to create clientInput " << endl;


    while (!isFinish){
	readPack = prodConsClient->consume();
	stringstream ss;
	ss << *readPack;
	ss.seekg(0, ios::end);
	int size = ss.tellg(); //size contain the size (in bytes) of the string

	cout << "message -------------- " << ss << endl;
	int g = htonl(size);
	n = write(newsockfd, (const char*)&g, sizeof(int));
	n = write(newsockfd, ss.str().c_str(), size);
	cout << "write on network " << endl;

	if (n < 0) 
	    cout << "ERROR writing from socket" << endl;
		  
    }

    close(newsockfd);

    return 0;

}

void *clientInputHandler(void* argv){

    //recover params for the thread
    cout << "Clien input start successful : " << pthread_self() << endl;
    ParamThreadInput *param = (ParamThreadInput*)argv;

    ProdCons<Pack*> *prodConsCommon = param->prodConsCommon;
    int newsockfd = param->sockfd;
    struct sockaddr_in serv_addr = *param->serv_addr;
    struct sockaddr_in cli_addr = *param->cli_addr;

    stringstream ss;
    char buffer[256];
    int n;
    bool isFinish = false;
    Debug *pack = new Debug();


    while (!isFinish){
	bzero(buffer,256);
	int a ;
	n = recv(newsockfd,(char*)&a,sizeof(int),MSG_WAITALL);
	a = ntohl(a);
	cout << "receive int a = " << a << endl;
	n = recv(newsockfd,buffer,a,MSG_WAITALL);
	if (n > 0) {

	    cout << "reading on socket " << n << " " << buffer << endl;

	    ss.str(string()); //to clear the stringstream 
	    ss.clear();
			
	    ss << buffer;

	    ss >> *pack;
			
	    cout << "this is pack : "<< *pack << endl;
	    prodConsCommon->produce(pack);
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
