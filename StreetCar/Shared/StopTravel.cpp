#include  "StopTravel.h"

using namespace std;

StopTravel::StopTravel() : Pack(){}

StopTravel::StopTravel(int idP) : Pack(){
    idPack = STOPTRAVEL;
    idPlayer = idP;
}

void StopTravel::print(std::ostream& f){
    f << STOPTRAVEL << " ";
    f << idPlayer << " ";
}
void StopTravel::read(std::istream& f){
    int idP;
    f >> idP;
    idPack = STOPTRAVEL;
    f >> idPlayer;
}
