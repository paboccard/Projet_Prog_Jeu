#include "StartedTravel.h"

using namespace std;

StartedTravel::StartedTravel(int idP, Travel travelOfTram): Pack(){
    idPack = STARTEDTRAVEL;
    idPlayer = idP;
    tram = travelOfTram;
}

ostream& operator << (std::ostream &f, StartedTravel &t){
    f << STARTEDTRAVEL << " ";
    f << t.idPlayer << " ";
    f << t.tram;
    return f;
}

istream& operator >> (std::istream &f, StartedTravel &t){
    int idP;
    f >> idP;
    t.idPack = STARTEDTRAVEL;
    f >> t.idPlayer;
    Travel travel;
    f >> travel;
    t.tram = travel;
    return f;
}
