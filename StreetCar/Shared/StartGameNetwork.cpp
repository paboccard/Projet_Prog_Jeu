#include "StartGameNetwork.h"

using namespace std;

StartGameNetwork::StartGameNetwork() : Pack(STARTGAMENETWORK){}

StartGameNetwork::StartGameNetwork(int numG) : Pack(STARTGAMENETWORK){
    numGame = numG;
}

void StartGameNetwork::print(std::ostream& f){
    Pack::print(f);
    f << numGame ;
}

void StartGameNetwork::read(std::istream& f){
    f >> numGame;
}
