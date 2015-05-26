#include "PileWhenTravel.h"

using namespace std;

PileWhenTravel::PileWhenTravel(vector<int> idP, vector<int> idH) : Pack(){
    idPlayers = idP;
    idHands = idH;
}


ostream& operator << (std::ostream &f, PileWhenTravel &t){
    f << t.idPlayers.size() << " ";
    for (unsigned int i = 0; i<t.idPlayers.size(); i++)
	f << t.idPlayers[i] << " ";
    f << t.idHands.size() << " ";
    for (unsigned int i = 0; i<t.idHands.size(); i++)
	f << t.idHands[i] << " ";
    return f;
}

istream& operator >> (std::istream &f, PileWhenTravel &t){
    int sizePlayers;
    f >> sizePlayers;
    t.idPlayers.clear();
    for (int i=0; i< sizePlayers; i++){
	int idP;
	f >> idP;
	t.idPlayers.push_back(idP);
    }
    int sizeHands;
    f >> sizeHands;
    t.idHands.clear();
    for (int i=0; i< sizeHands; i++){
	int idH;
	f >> idH;
	t.idHands.push_back(idH);
    }
    return f;
}
