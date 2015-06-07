#include "ResponseRefresh.h"

using namespace std;

ResponseRefresh::ResponseRefresh(vector<GameNetwork> game) : Pack(RESPONSEREFRESH){
  gameNetwork = game;
}

void ResponseRefresh::print(std::ostream& f){
      Pack::print(f);
      f << gameNetwork.name << " " << gameNetwork.nbrPlayers;
}

void ResponseRefresh::read(std::istream& f){
  f >> name;
  f >> nbrPlayers;
}
