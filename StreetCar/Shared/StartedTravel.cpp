#include "StartedTravel.h"

using namespace std;

StartedTravel::StartedTravel() : Pack() {}

StartedTravel::StartedTravel(int idP, Travel travelOfTram): Pack(){
    idPack = STARTEDTRAVEL;
    idPlayer = idP;
    tram = travelOfTram;
}


void StartedTravel::print(std::ostream& f){
    f << STARTEDTRAVEL << " ";
    f << idPlayer << " ";
    f << tram;
}

void StartedTravel::read(std::istream& f){
    int idP;
    f >> idP;
    idPack = STARTEDTRAVEL;
    f >> idPlayer;
    Travel travel;
    f >> travel;
    tram = travel;
}
