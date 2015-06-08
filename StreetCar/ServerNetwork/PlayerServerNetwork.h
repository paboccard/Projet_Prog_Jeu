#ifndef PLAYERSERVERNETWORK_H
#define PLAYERSERVERNETWORK_H

#include "../Shared/Player.h"
#include "../Shared/Packs.h"
#include "../Shared/Pack.h"
#include "../Shared/ProdCons.h"
#include "../Shared/Board.h"
#include "PlayerServerNetwork.h"
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class PlayerServerNetwork : public Player
{
 public:
    ProdCons<Pack*> *circularQueue;
    int sockfd;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    
    PlayerServerNetwork();
    PlayerServerNetwork(ProdCons<Pack*> *queue, int sock, struct sockaddr_in serv, struct sockaddr_in cli);
    ~PlayerServerNetwork();
 
};

#endif // PLAYERSERVERNETWORK_H
