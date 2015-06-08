#include "CreateGameNetwork.h"

using namespace std;

CreateGameNetwork::CreateGameNetwork() : Pack(CREATEGAMENETWORK){}

CreateGameNetwork::CreateGameNetwork(int nbrP, string nameG) : Pack(CREATEGAMENETWORK){
    nbrPlayer = nbrP;
    nameGame = nameG;
}

void CreateGameNetwork::print(ostream &f){
    Pack::print(f);
    f << nbrPlayer << " " << nameGame;
}

void CreateGameNetwork::read(istream &f){
    
    f >> nbrPlayer;
    f >> nameGame;
}
