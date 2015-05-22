#include "Won.h"

using namespace std;

Won::Won(int idP) : Pack(){
    idPack = WON;
    idPlayer = idP;
}

ostream& operator << (ostream &f, Won &t){
    f << WON << " ";
    f << t.idPlayer << " ";
    return f;
}

istream& operator >> (istream &f, Won &t){
    int idP;
    f >> idP;
    t.idPack = WON;
    f >> t.idPlayer;
    return f;
}
