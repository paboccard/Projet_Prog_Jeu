#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Tile.h"


using namespace std;


int main(int argc, char *argv[])
{
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  char buffer[256];
  if (argc < 3) {
      cout << "usage " << argv[0] << " hostname port" << endl;
      exit(0);
  }
  portno = 20001;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) 
      cout << "ERROR opening socket" << endl;

  server = gethostbyname(argv[1]);
  if (server == NULL) {
      cout << "ERROR, no such host " << endl;
      exit(0);
  }
  bzero((char *) &serv_addr, sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;

  bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);

  serv_addr.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
      cout << "ERROR connecting " <<endl;
  cout << "Please enter the message: " << endl; 

  //bzero(buffer,256);

  int idPlayer = 2;
  int nbrTiles = 1;
  Tile test ;//= new Tile();
  test.tree = true;
  Rail r1, r2, r3;
  r1.s1 = 2;
  r1.s2 = 3;
  r2.s1 = 1;
  r2.s2 = 1;
  r3.s1 = 1;
  r3.s2 = 2;
  test.ways.push_back(r1);
  test.ways.push_back(r2);
  test.ways.push_back(r3);
  test.turn = 1;
  test.type = Curve;
  test.idPlayer = -1;
  test.access[1] = 0;
  test.access[2] = 1;
  test.access[3] = 0;
  test.access[4] = 1;
  stringstream ss;
  ss << idPlayer << " " << nbrTiles;
  
  for (int i = 0; i<nbrTiles;i++)
      ss << " " << test;

  ss.seekg(0, ios::end);
  int size = ss.tellg(); //size contain the size (in bytes) of the string

  //  cin >> buffer;

  n = write(sockfd, ss.str().c_str(), size);

  if (n < 0) 
      cout << "ERROR wrinting to socket" << endl;

  bzero(buffer,256);

  n = read(sockfd, buffer, 255);

  if (n < 0) 
      cout << "ERROR reading from socket" << endl;

  cout << buffer;

  close(sockfd);

  return 0;
}
