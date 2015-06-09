#include "IWantPlayNetwork.h"

using namespace std;

IWantPlayNetwork::IWantPlayNetwork() : Pack(IWANTPLAYNETWORK){}

IWantPlayNetwork::IWantPlayNetwork(Profile pro, int numG) : Pack(IWANTPLAYNETWORK){
    profile = pro;
    numGame = numG;
}

void IWantPlayNetwork::print(ostream &f){
    Pack::print(f);
    f << profile << " " << numGame;
}

void IWantPlayNetwork::read(istream &f){
    f >> profile;
    f >> numGame;
}
