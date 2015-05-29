#include "PlayedTravel.h"

using namespace std;

PlayedTravel::PlayedTravel() : Pack(PLAYEDTRAVEL){}

PlayedTravel::PlayedTravel(int idNextP, Travel travelOfTram): Pack(PLAYEDTRAVEL){
    idNextPlayer = idNextP;
    tram = travelOfTram;
}

void PlayedTravel::print(ostream& f){
    Pack::print(f);
    f << idNextPlayer << " ";
    f << tram;
}

void PlayedTravel::read(istream& f){
    f >> idNextPlayer;
    Travel travel;
    f >> travel;
    tram = travel;
}
