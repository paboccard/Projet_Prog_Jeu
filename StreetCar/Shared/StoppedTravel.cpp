#include "StoppedTravel.h"
#include <fstream>

using namespace std;

StoppedTravel::StoppedTravel() : Pack(STOPPEDTRAVEL){}

StoppedTravel::StoppedTravel(int idNextP) : Pack(STOPPEDTRAVEL){
    idNextPlayer = idNextP;
}

void StoppedTravel::print(std::ostream& f){
    Pack::print(f);
    f << idNextPlayer << " ";
}

void StoppedTravel::read(std::istream& f){
    f >> idNextPlayer;
}
