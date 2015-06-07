#ifndef IWANTPLAYNETWORK_H
#define IWANTPLAYNETWORK_H

#include "Pack.h"
#include "Profile.h"
#include "ProdCons.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>


class IWantPlayNetwork : public Pack{
    
 public:
    
    Profile profile;
    int numGame;
    ProdCons<Pack*> *prodConsClient;
    int sockfd;
    struct sockaddr_in serv_addr, cli_addr;


    IWantPlayNetwork();
    IWantPlayNetwork(Profile pro, int numG);

    void print(std::ostream& f);
    void read(std::istream& f);

    friend std::ostream& operator << (std::ostream &f, IWantPlayNetwork &t){
	t.print(f);
	return f;
    };
    friend std::istream& operator >> (std::istream &f, IWantPlayNetwork &t){
	t.read(f);
	return f;
    };

};

#endif
