#include "CircularQueueClient.h"

CircularQueueClient::CircularQueueClient() : Pack(){}

CircularQueueClient::CircularQueueClient(ProdCons<Pack*> *prod) : Pack(CIRCULARQUEUECLIENT){
      prodConsClient = prod;
}

void CircularQueueClient::print(std::ostream& f){}

void CircularQueueClient::read(std::istream& f){}
