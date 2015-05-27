#include "PlayedTravel.h"

using namespace std;

PlayedTravel::PlayedTravel() : Pack(){}

PlayedTravel::PlayedTravel(int idNextP, Travel travelOfTram): Pack(){
    idPack = PLAYEDTRAVEL;
    idNextPlayer = idNextP;
    tram = travelOfTram;
}

void PlayedTravel::print(ostream& f){
    f << PLAYEDTRAVEL << " ";
    f << idNextPlayer << " ";
    f << tram;
}

void PlayedTravel::read(istream& f){
    int i;
    f >> i;
    idPack = PLAYTRAVEL;
    f >> idNextPlayer;
    Travel travel;
    f >> travel;
    tram = travel;
}
