#include "CreateGameNetwork.h"

using namespace std;

CreateGameNetwork::CreateGameNetwork() : Pack(CREATEGAMENETWORK){

}

CreateGameNetwork::CreateGameNetwork(GameNetwork g) : Pack(CREATEGAMENETWORK){
	gameNetwork.name = g.name;
	gameNetwork.nbrPlayers = g.nbrPlayers;
}

void CreateGameNetwork::print(ostream &f){
    Pack::print(f);
	f << gameNetwork.nbrPlayers << " " << gameNetwork.name;
}

void CreateGameNetwork::read(istream &f){
    
	f >> gameNetwork.nbrPlayers;
	f >> gameNetwork.name;
}
