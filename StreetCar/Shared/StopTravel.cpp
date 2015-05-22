#include  "StopTravel.h"

using namespace std;

StopTravel::StopTravel(int idP) : Pack(){
    idPack = STOPTRAVEL;
    idPlayer = idP;
}

ostream& operator << (ostream &f, StopTravel &t){
    f << STOPTRAVEL << " ";
    f << t.idPlayer << " ";
    return f;
}

istream& operator >> (istream &f, StopTravel &t){
    int idP;
    f >> idP;
    t.idPack = STOPTRAVEL;
    f >> t.idPlayer;
    return f;
}
