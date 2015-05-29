#include "StartedTravel.h"

using namespace std;

StartedTravel::StartedTravel() : Pack(STARTEDTRAVEL) {}

StartedTravel::StartedTravel(int idP, Travel travelOfTram): Pack(STARTEDTRAVEL){
    idPlayer = idP;
    tram = travelOfTram;
}


void StartedTravel::print(std::ostream& f){
    Pack::print(f);
    f << idPlayer << " ";
    f << tram;
}

void StartedTravel::read(std::istream& f){
    f >> idPlayer;
    Travel travel;
    f >> travel;
    tram = travel;
}
