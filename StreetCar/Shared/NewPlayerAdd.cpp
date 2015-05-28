#include "NewPlayerAdd.h"

using namespace std;

NewPlayerAdd::NewPlayerAdd() : Pack(NEWPLAYERADD){}

NewPlayerAdd::NewPlayerAdd(Profile pro, int idP) : Pack(NEWPLAYERADD){
    profile = pro;
    idPlayer = idP;
}

void NewPlayerAdd::print(ostream &f){
    Pack::print(f);
    f << profile << " ";
    f << idPlayer;
}

void NewPlayerAdd::read(istream &f){
    f >> profile;
    f >> idPlayer;
}
