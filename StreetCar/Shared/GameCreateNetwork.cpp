#include "GameCreateNetwork.h"

using namespace std;

GameCreateNetwork::GameCreateNetwork() : Pack(GAMECREATENETWORK){}

void GameCreateNetwork::print(std::ostream& f){
    Pack::print(f);
    f << idPlayer << " ";
}

void GameCreateNetwork::read(std::istream& f){
    f >> idPlayer;
}
