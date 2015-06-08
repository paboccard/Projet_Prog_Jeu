#include "ResponsePlayerRefresh.h"

using namespace std;

ResponsePlayerRefresh::ResponsePlayerRefresh() : Pack(RESPONSEPLAYERREFRESH){}

ResponsePlayerRefresh::ResponsePlayerRefresh(vector<Profile> p) : Pack(RESPONSEPLAYERREFRESH){
    profiles= p;
}

void ResponsePlayerRefresh::print(std::ostream& f){
      Pack::print(f);
      f << profiles.size() << " ";
      for (unsigned int i = 0; i<profiles.size() ; i++)
	  f << profiles[i] << " ";
}

void ResponsePlayerRefresh::read(std::istream& f){
    int nbr;
    f >> nbr;
    for (int i = 0; i<nbr; i++)
	f >> profiles[i];
}
