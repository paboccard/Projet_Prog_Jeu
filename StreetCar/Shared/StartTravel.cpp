#include "StartTravel.h"

using namespace std;

StartTravel::StartTravel(int idP, vector<Tile> tr) : Pack() {
    idPack = STARTTRAVEL;
    idPlayer = idP;
    travel = tr;
}

// StartTravel::writePack(int fd){
//     stringstream ss;
//     ss << idPlayer << " " << nbrTiles ;

//     for (int i = 0; i<nbrTiles<i++)
// 	ss << " " << t[i];

//     ss.seekg(0, ios::end);
//     int size = ss.tellg(); //size contain the size (in bytes) of the string

//     write(fd, ss.str().c_str(), size);
// }


ostream& operator << (std::ostream &f, StartTravel &t){
    f << 0 << " ";
    f << t.idPlayer << " ";
    f << t.travel.size() << " ";
    for (unsigned int i = 0; i<t.travel.size(); i++)
	f << t.travel[i] << " ";
    return f;
}

istream& operator >> (std::istream &f, StartTravel &t){
    int idP;
    f >> idP;
    t.idPack = STARTTRAVEL;
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
