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
#include "Tile.h"

using namespace std;

int main(int argc, char **argv){
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  stringstream buffer2;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  int n;

  //create a socket
  // socket(int domain, int type, int protocol)
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
    cout << "ERROR opening socket" << endl ;

  //clear adresse structure
  bzero((char *)&serv_addr, sizeof(serv_addr));

  portno = 20001;

  //setup the host_addr structure for use in bind call
  //server byte order
  serv_addr.sin_family = AF_INET;

  //automatically be filled with current host's IP adresse
  serv_addr.sin_addr.s_addr = INADDR_ANY;

  //convert short integer value for port must be converted into network byte
  serv_addr.sin_port = htons(portno);

  // bind(int fd, struct sockaddr *local_addr, socklen_t addr_length)
  // bind() passes file descriptor, the address structure, 
  // and the length of the address structure
  // This bind() call will bind  the socket to the current IP address on port, portno
  if (bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) <0)
    cout << "ERROR on binding" << endl;

  // This listen() call tells the socket to listen to the incoming connections.
  // The listen() function places all incoming connection into a backlog queue
  // until accept() call accepts the connection.
  // Here, we set the maximum size for the backlog queue to 5.
  listen(sockfd,5);

  // The accept() call actually accepts an incoming connection
  clilen = sizeof(cli_addr);

  // This accept() function will write the connecting client's address info 
  // into the the address structure and the size of that structure is clilen.
  // The accept() returns a new socket file descriptor for the accepted connection.
  // So, the original socket file descriptor can continue to be used 
  // for accepting new connections while the new socker file descriptor is used for
  // communicating with the connected client.
  newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr, &clilen);
  if (newsockfd < 0) 
    cout << "ERROR on accept" << endl;
  
  cout << "server: got connection from " << inet_ntoa(cli_addr.sin_addr) << " port " << ntohs(cli_addr.sin_port) << endl ;
  
  // This send() function sends the 13 bytes of the string to the new socket
  send(newsockfd, "Hello, world!\n", 13, 0);

  bzero(buffer,256);

  n = read(newsockfd,buffer,255);

  buffer2 << buffer;
  Tile tile;
  buffer2 >> tile;
  
  if (n < 0) 
    cout << "ERROR reading from socket" << endl;
  cout << "Here is the message: "<< tile << endl;

  close(newsockfd);
  close(sockfd);
  return 0;

  /*
  Tile t[3];
  for (int i = 0; i<3; i++)
    t[i] = new Tile();
  PlayedTravel pt = new PlayedTravel(3,3,t);
  */

}
