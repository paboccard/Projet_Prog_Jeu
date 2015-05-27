#include "Won.h"

using namespace std;

Won::Won() : Pack(){}

Won::Won(int idP) : Pack(){
    idPack = WON;
    idPlayer = idP;
}

void Won::print(std::ostream& f){
    f << WON << " ";
    f << idPlayer << " ";
}

void Won::read(std::istream& f){
    int idP;
    f >> idP;
    idPack = WON;
    f >> idPlayer;
}
