#include "ResponseRefresh.h"

using namespace std;

ResponseRefresh::ResponseRefresh(): Pack(RESPONSEREFRESH) {}

ResponseRefresh::ResponseRefresh(vector<GameNetwork> game) : Pack(RESPONSEREFRESH){
	gameNetwork = game;
}

void ResponseRefresh::print(std::ostream& f){
	Pack::print(f);
	f << gameNetwork.size() << " ";
	for (unsigned int i = 0; i<gameNetwork.size() ; i++)
		f << gameNetwork[i].name << " " << gameNetwork[i].nbrPlayers;
}

void ResponseRefresh::read(std::istream& f){
	int nbr;
	f >> nbr;
	gameNetwork.clear();
	for (int i = 0; i<nbr; i++){
		GameNetwork tmp;
		f >> tmp.name;
		f >> tmp.nbrPlayers;
		gameNetwork.push_back(tmp);
	}
}
