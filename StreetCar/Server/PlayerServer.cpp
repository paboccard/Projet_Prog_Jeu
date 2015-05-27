#include "PlayerServer.h"

PlayerServer::PlayerServer() : Player(){
    //ctor
}

PlayerServer::PlayerServer(ProdCons<Pack*> *queue){
    circularQueue = queue;
}

PlayerServer::~PlayerServer()
{
    //dtor
}
