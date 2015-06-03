#include "PlayTravel.h"

using namespace std;

PlayTravel::PlayTravel() : Pack(PLAYTRAVEL){}

PlayTravel::PlayTravel(int idP, vector<Point> tr) : Pack(PLAYTRAVEL) {
    idPlayer = idP;
    travel = tr;
}

void PlayTravel::print(std::ostream& f){
    Pack::print(f);
    f << idPlayer << " ";
    f << travel.size() << " ";
    for (unsigned int i = 0; i<travel.size(); i++)
	f << travel[i] << " ";
}

void PlayTravel::read(std::istream& f){
    f >> idPlayer;
    int nbInVectorTravel;
    f >> nbInVectorTravel;
    travel.clear();
    for (int i = 0; i< nbInVectorTravel; i++){
	Point p;
	f >> p;
	travel.push_back(p);
    }
}
