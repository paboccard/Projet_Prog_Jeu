#include  "StopTravel.h"

using namespace std;

StopTravel::StopTravel() : Pack(STOPTRAVEL){}

StopTravel::StopTravel(int idP) : Pack(STOPTRAVEL){
    idPlayer = idP;
}

void StopTravel::print(std::ostream& f){
    Pack::print(f);
    f << idPlayer << " ";
}
void StopTravel::read(std::istream& f){
    f >> idPlayer;
}
