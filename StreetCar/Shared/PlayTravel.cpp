#include "PlayTravel.h"

using namespace std;

PlayTravel::PlayTravel() : Pack(){}

PlayTravel::PlayTravel(int idP, vector<Tile> tr) : Pack() {
    idPack = PLAYTRAVEL;
    idPlayer = idP;
    travel = tr;
}

void PlayTravel::print(std::ostream& f){
    f << PLAYTRAVEL << " ";
    f << idPlayer << " ";
    f << travel.size() << " ";
    for (unsigned int i = 0; i<travel.size(); i++)
	f << travel[i] << " ";
}

void PlayTravel::read(std::istream& f){
    int idP;
    f >> idP;
    idPack = PLAYTRAVEL;
    f >> idPlayer;
    int nbInVectorTravel;
    f >> nbInVectorTravel;
    travel.clear();
    for (int i = 0; i< nbInVectorTravel; i++){
	Tile tileTmp;
	f >> tileTmp;
	travel.push_back(tileTmp);
    }
}
