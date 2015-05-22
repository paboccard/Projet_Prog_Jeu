#include "PlayedTravel.h"

using namespace std;

PlayedTravel::PlayedTravel(int idNextP, Travel travelOfTram): Pack(){
    idPack = PLAYEDTRAVEL;
    idNextPlayer = idNextP;
    tram = travelOfTram;
}

ostream& operator << (std::ostream &f, PlayedTravel &t){
    f << PLAYEDTRAVEL << " ";
    f << t.idNextPlayer << " ";
    f << t.tram;
    return f;
}

istream& operator >> (std::istream &f, PlayedTravel &t){
    int idP;
    f >> idP;
    t.idPack = PLAYTRAVEL;
    f >> t.idNextPlayer;
    Travel travel;
    f >> travel;
    t.tram = travel;
    return f;
}
