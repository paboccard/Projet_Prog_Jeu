#include "NewPlayerAdd.h"

using namespace std;

NewPlayerAdd::NewPlayerAdd() : Pack(){}

NewPlayerAdd::NewPlayerAdd(Profile pro, int idP) : Pack(){
    profile = pro;
    idPlayer = idP;
}

void NewPlayerAdd::print(ostream &f){
    f << profile;
    f << idPlayer;
}

void NewPlayerAdd::read(istream &f){
    f >> profile;
    f >> idPlayer;
}
