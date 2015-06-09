#include "GameCreateNetwork.h"

using namespace std;

GameCreateNetwork::GameCreateNetwork() : Pack(GAMECREATENETWORK){}

GameCreateNetwork::GameCreateNetwork(GameNetwork g) : Pack(GAMECREATENETWORK){
    gameNetwork.name = g.name;
    gameNetwork.nbrPlayers = g.nbrPlayers;
}

void GameCreateNetwork::print(std::ostream& f){
    Pack::print(f);
    f << gameNetwork.nbrPlayers << " " << gameNetwork.name;
}

void GameCreateNetwork::read(std::istream& f){
    f >> gameNetwork.nbrPlayers;
    f >> gameNetwork.name;

}
