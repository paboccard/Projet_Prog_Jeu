#include "PlayedTravel.h"

using namespace std;

PlayedTravel::PlayedTravel() : Pack(){}

PlayedTravel::PlayedTravel(Travel travelOfTram): Pack(){
    idPack = PLAYEDTRAVEL;
    tram = travelOfTram;
}

void PlayedTravel::print(ostream& f){
    f << PLAYEDTRAVEL << " ";
    f << tram;
}

void PlayedTravel::read(istream& f){
    int i;
    f >> i;
    idPack = PLAYTRAVEL;
    Travel travel;
    f >> travel;
    tram = travel;
}
