#include "StoppedTravel.h"
#include <fstream>

using namespace std;

StoppedTravel::StoppedTravel(int idNextP) : Pack(){
    idPack = STOPTRAVEL;
    idNextPlayer = idNextP;
}

ostream& operator << (ostream &f, StoppedTravel &t){
    f << STOPPEDTRAVEL << " ";
    f << t.idNextPlayer << " ";
    return f;
}

istream& operator >> (istream &f, StoppedTravel &t){
    int idP;
    f >> idP;
    t.idPack = STOPPEDTRAVEL;
    f >> t.idNextPlayer;
    return f;
}
