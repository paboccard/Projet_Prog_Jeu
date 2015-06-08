#include "GameCreateNetwork.h"

using namespace std;

GameCreateNetwork::GameCreateNetwork() : Pack(GAMECREATENETWORK){}

void GameCreateNetwork::print(std::ostream& f){
    Pack::print(f);
}

void GameCreateNetwork::read(std::istream& f){
}
