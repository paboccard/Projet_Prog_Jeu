#include "StartTravel.h"

using namespace std;

StartTravel::StartTravel() : Pack(STARTTRAVEL){}

StartTravel::StartTravel(int idP, vector<Tile> tr) : Pack(STARTTRAVEL) {
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

void StartTravel::print(std::ostream& f){
    Pack::print(f);
    f << idPlayer << " ";
    f << travel.size() << " ";
    for (unsigned int i = 0; i<travel.size(); i++)
	f << travel[i] << " ";
}

void StartTravel::read(std::istream& f){
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
