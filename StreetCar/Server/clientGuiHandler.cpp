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

using namespace std;

//int main(int argc, char **argv){
void *clientGuiInputHandler(void* argv){

    cout << "Event thread clientGuitInputHandler started successful" << endl;
    // int sockfd, newsockfd, portno;
    //  socklen_t clilen;
    //  stringstream buffer2;
    //  char buffer[256];
    //  struct sockaddr_in serv_addr, cli_addr;
    //  int n;

    //  //create a socket
    //  // socket(int domain, int type, int protocol)
    //  sockfd = socket(AF_INET, SOCK_STREAM, 0);
    //  if (sockfd < 0)
    //    cout << "ERROR opening socket" << endl ;

    //  //clear adresse structure
    //  bzero((char *)&serv_addr, sizeof(serv_addr));

    //  portno = 20001;

    //  //setup the host_addr structure for use in bind call
    //  //server byte order
    //  serv_addr.sin_family = AF_INET;

    //  //automatically be filled with current host's IP adresse
    //  serv_addr.sin_addr.s_addr = INADDR_ANY;

    //  //convert short integer value for port must be converted into network byte
    //  serv_addr.sin_port = htons(portno);

    //  // bind(int fd, struct sockaddr *local_addr, socklen_t addr_length)
    //  // bind() passes file descriptor, the address structure, 
    //  // and the length of the address structure
    //  // This bind() call will bind  the socket to the current IP address on port, portno
    //  if (bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) <0)
    //    cout << "ERROR on binding" << endl;

    //  // This listen() call tells the socket to listen to the incoming connections.
    //  // The listen() function places all incoming connection into a backlog queue
    //  // until accept() call accepts the connection.
    //  // Here, we set the maximum size for the backlog queue to 5.
    //  listen(sockfd,5);

    //  // The accept() call actually accepts an incoming connection
    //  clilen = sizeof(cli_addr);

    //  // This accept() function will write the connecting client's address info 
    //  // into the the address structure and the size of that structure is clilen.
    //  // The accept() returns a new socket file descriptor for the accepted connection.
    //  // So, the original socket file descriptor can continue to be used 
    //  // for accepting new connections while the new socker file descriptor is used for
    //  // communicating with the connected client.
    //  newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr, &clilen);
    //  if (newsockfd < 0) 
    //    cout << "ERROR on accept" << endl;
  
    //  cout << "server: got connection from " << inet_ntoa(cli_addr.sin_addr) << " port " << ntohs(cli_addr.sin_port) << endl ;
  
    //  // This send() function sends the 13 bytes of the string to the new socket
    //  //send(newsockfd, "Hello, world!\n", 13, 0);

    //  //bzero(buffer,256);

    //  //Creation d'un Tile
    //  Tile tile ;//= new Tile();
    //  tile.tree = true;
    //  Rail r1, r2, r3;
    //  r1 = (Rail){2,3};
    //  r2 = (Rail){1,1};
    //  r3 = (Rail){1,2};
    //  tile.ways.clear();
    //  tile.ways.push_back(r1);
    //  tile.ways.push_back(r2);
    //  tile.ways.push_back(r3);
    //  tile.turn = 2;
    //  tile.type = Curve;
    //  tile.idPlayer = 3;
    //  tile.access[0] = 1;
    //  tile.access[1] = 1;
    //  tile.access[2] = 0;
    //  tile.access[3] = 1;

    //  //Creation d'un Tile
    //  Tile tile2 ;//= new Tile();
    //  tile2.tree = false;
    //  r1 = (Rail){2,3};
    //  r2 = (Rail){1,1};
    //  r3 = (Rail){1,2};
    //  tile2.ways.clear();
    //  tile2.ways.push_back(r1);
    //  tile2.ways.push_back(r2);
    //  tile2.ways.push_back(r3);
    //  tile2.turn = 2;
    //  tile2.type = CrossCurves;
    //  tile2.idPlayer = 3;
    //  tile2.access[0] = 1;
    //  tile2.access[1] = 1;
    //  tile2.access[2] = 1;
    //  tile2.access[3] = 1;

    //  vector<Tile> tiles;
    //  tiles.clear();
    //  tiles.push_back(tile);
    //  tiles.push_back(tile2);

    //  PlayedTile playedTile = PlayedTile(3,tiles);

    //  stringstream ss;
    //  ss << playedTile;

    //  ss.seekg(0, ios::end);
    //  int size = ss.tellg(); //size contain the size (in bytes) of the string

    //  n = write(newsockfd, ss.str().c_str(), size);
  
    //  if (n < 0) 
    //    cout << "ERROR writing from socket" << endl;
  
    //  n = read(newsockfd,buffer,255);
  
    //  ss.str(string()); //to clear the stringstream 
    //  ss.clear();
    //  ss << buffer;
  
    //  // buffer2 >> tile;
  
    //  if (n < 0) 
    //    cout << "ERROR reading from socket" << endl;
    //  cout << "Here is the message: "<< ss.str() << endl;

    //  close(newsockfd);
    //  close(sockfd);
    return 0;

    /*
  Tile t[3];
  for (int i = 0; i<3; i++)
    t[i] = new Tile();
  PlayedTravel pt = new PlayedTravel(3,3,t);
    */

}

void *clientGuiOutputHandler(void* argv){

    cout << "Event thread clientGuitOutputHandler started successful" << endl;
    return 0;
}

void *automateInputHandler(void* argv){

    cout << "Event thread automateInputHandler started successful" << endl;
    return 0;
}

void *automateOutputHandler(void* argv){

    cout << "Event thread automateOutputHandler started successful" << endl;
    return 0;
}
