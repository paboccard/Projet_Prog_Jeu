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

    cout << "Event thread client1Handler started successful" << endl;

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
    
    cout << "UN CLIENT S'EST CONNECTE " << endl;

    CircularQueueClient *circular = new CircularQueueClient(prodConsClient);
    prodConsCommon->produce(circular);

    //    cout << "server: got connection from " << inet_ntoa(cli_addr.sin_addr) << " port " << ntohs(cli_addr.sin_port) << endl ;
    
    //create the listener thread
    pthread_t client;
    ParamThreadInput paramInput = {prodConsCommon,newsockfd,&serv_addr,&cli_addr};
    
    if (pthread_create(&client, NULL, clientInputHandler,(void *)(&paramInput))==0){
	cout << "End of event thread clientInput " << endl;
    }else
	cout << "ERROR, impossible to create clientInput " << endl;


    while (!isFinish){
	readPack = prodConsClient->consume();

	stringstream ss;
	ss << *readPack;
	
	ss.seekg(0, ios::end);
	int size = ss.tellg(); //size contain the size (in bytes) of the string
	
	n = write(newsockfd, ss.str().c_str(), size);
	
	if (n < 0) 
	    cout << "ERROR writing from socket" << endl;
    }
    
    close(newsockfd);

    return 0;

}

void *clientInputHandler(void* argv){

    //recover params for the thread
    ParamThread *param = (ParamThread*)argv;

    ProdCons<Pack*> *prodConsCommon = param->prodConsCommon;
    int newsockfd = param->sockfd;
    struct sockaddr_in serv_addr = *param->serv_addr;
    struct sockaddr_in cli_addr = *param->cli_addr;

    stringstream ss;
    char buffer[256];
    int n;
    bool isFinish = false;
    Pack *pack;

    while (!isFinish){
	
	bzero(buffer,256);
	n = read(newsockfd,buffer,255);
	
	ss.str(string()); //to clear the stringstream 
	ss.clear();

	ss << buffer;
	ss >> *pack;

	if (n < 0) 
	    cout << "ERROR reading from socket" << endl;
	else
	    prodConsCommon->produce(pack);

    }
    close(newsockfd);
    return 0;
}
