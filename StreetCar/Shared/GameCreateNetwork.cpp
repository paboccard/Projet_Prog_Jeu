#include "GameCreateNetwork.h"

using namespace std;

GameCreateNetwork::GameCreateNetwork() : Pack(GAMECREATENETWORK){}

GameCreateNetwork::GameCreateNetwork(int numG) : Pack(GAMECREATENETWORK){
    numGame = numG;
}

void GameCreateNetwork::print(std::ostream& f){
    Pack::print(f);
    f << numGame ;
}

void GameCreateNetwork::read(std::istream& f){
    f >> numGame;
}
