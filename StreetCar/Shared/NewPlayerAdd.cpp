#include "NewPlayerAdd.h"

using namespace std;

NewPlayerAdd::NewPlayerAdd() : Pack(){}

NewPlayerAdd::NewPlayerAdd(Profile pro, int idP) : Pack(){
    idPack = NEWPLAYERADD;
    profile = pro;
    idPlayer = idP;
}

void NewPlayerAdd::print(ostream &f){
    f << NEWPLAYERADD << " ";
    f << profile << " ";
    f << idPlayer;
}

void NewPlayerAdd::read(istream &f){
    int i;
    f >> i;
    idPack = NEWPLAYERADD;
    f >> profile;
    f >> idPlayer;
}
