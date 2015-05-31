#include "PlayerServer.h"

PlayerServer::PlayerServer() : Player(){
    //ctor
    cout << "la" << endl;
    circularQueue = new ProdCons<Pack*>();                     // KILL ME
}

PlayerServer::PlayerServer(ProdCons<Pack*> *queue){
    circularQueue = queue;
}

PlayerServer::~PlayerServer()
{
    //dtor
}
