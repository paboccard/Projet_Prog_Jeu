#include "RefreshPlayerGame.h"

using namespace std;

RefreshPlayerGame::RefreshPlayerGame(vector<Profile> p) : Pack(REFRESHPLAYERGAME){
    players = p;
}


void RefreshPlayerGame::print(std::ostream& f){
    Pack::print(f);
    f << players.size();
    for (unsigned int i = 0; i<players.size(); i++)
	f << players[i] << " ";
}

void RefreshPlayerGame::read(std::istream& f){
    int nbr;
    f >> nbr;
    for (int i=0; i<nbr; i++){
	Profile p;
	f >> p;
	players.push_back(p);
    }
}
