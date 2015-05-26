#include "PileWhenTravel.h"

using namespace std;

PileWhenTravel::PileWhenTravel() : Pack(){}

PileWhenTravel::PileWhenTravel(vector<int> idP, vector<int> idH) : Pack(){
    idPlayers = idP;
    idHands = idH;
}

void PileWhenTravel::print(ostream& f){
    f << idPlayers.size() << " ";
    for (unsigned int i = 0; i<idPlayers.size(); i++)
	f << idPlayers[i] << " ";
    f << idHands.size() << " ";
    for (unsigned int i = 0; i<idHands.size(); i++)
	f << idHands[i] << " ";
}

void PileWhenTravel::read(istream& f){
    int sizePlayers;
    f >> sizePlayers;
    idPlayers.clear();
    for (int i=0; i< sizePlayers; i++){
	int idP;
	f >> idP;
	idPlayers.push_back(idP);
    }
    int sizeHands;
    f >> sizeHands;
    idHands.clear();
    for (int i=0; i< sizeHands; i++){
	int idH;
	f >> idH;
	idHands.push_back(idH);
    }
}
