#include "StoppedTravel.h"
#include <fstream>

using namespace std;

StoppedTravel::StoppedTravel() : Pack(){}

StoppedTravel::StoppedTravel(int idNextP) : Pack(){
    idPack = STOPTRAVEL;
    idNextPlayer = idNextP;
}

void StoppedTravel::print(std::ostream& f){
    f << STOPPEDTRAVEL << " ";
    f << idNextPlayer << " ";
}

void StoppedTravel::read(std::istream& f){
    int idP;
    f >> idP;
    idPack = STOPPEDTRAVEL;
    f >> idNextPlayer;
}
