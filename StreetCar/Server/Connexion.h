#ifndef CONNEXION_H
#define CONNEXION_H

#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <iostream>
#include <string.h>
#include <arpa/inet.h>

class Connexion{
    
 public:
    int sockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    
    Connexion();
    

};

#endif
