#include "PlayerServerNetwork.h"

PlayerServerNetwork::PlayerServerNetwork() : Player(){
    //ctor
    cout << "la" << endl;
    circularQueue = new ProdCons<Pack*>();                     // KILL ME
}

PlayerServerNetwork::PlayerServerNetwork(ProdCons<Pack*> *queue, int sock, struct sockaddr_in serv, struct sockaddr_in cli) : Player(){
    circularQueue = queue;
    sockfd = sock;
    serv_addr = serv;
    cli_addr = cli;
}

PlayerServerNetwork::~PlayerServerNetwork()
{
    //dtor
}
