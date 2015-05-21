#include "PlayTravel.h"

using namespace std;

PlayTravel::PlayTravel(int idP, vector<Tile> tr) : Pack() {
    idPack = PLAYTRAVEL;
    idPlayer = idP;
    travel = tr;
}

ostream& operator << (std::ostream &f, PlayTravel &t){
    f << 1 << " ";
    f << t.idPlayer << " ";
    f << t.travel.size() << " ";
    for (unsigned int i = 0; i<t.travel.size(); i++)
	f << t.travel[i] << " ";
    return f;
}

istream& operator >> (std::istream &f, PlayTravel &t){
    int idP;
    f >> idP;
    t.idPack = PLAYTRAVEL;
    f >> t.idPlayer;
    int nbInVectorTravel;
    f >> nbInVectorTravel;
    for (int i = 0; i< nbInVectorTravel; i++){
	Tile tileTmp;
	f >> tileTmp;
	t.travel.push_back(tileTmp);
    }
    return f;
}
