#include "PlayerServer.h"

PlayerServer::PlayerServer() : Player(){
    //ctor
}

PlayerServer::PlayerServer(ProdCons<Pack*> *queue) : Player(){
    circularQueue = queue;
}

PlayerServer::~PlayerServer()
{
    //dtor
}
