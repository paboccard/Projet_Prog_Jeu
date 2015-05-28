#include "Won.h"

using namespace std;

Won::Won() : Pack(WON){}

Won::Won(int idP) : Pack(WON){
    idPlayer = idP;
}

void Won::print(std::ostream& f){
    Pack::print(f);
    f << idPlayer << " ";
}

void Won::read(std::istream& f){
    f >> idPlayer;
}
