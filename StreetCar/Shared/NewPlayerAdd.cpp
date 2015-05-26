#include "NewPlayerAdd.h"

using namespace std;

NewPlayerAdd::NewPlayerAdd(Profile pro, int idP) : Pack(){
    profile = pro;
    idPlayer = idP;
}

ostream& operator << (ostream &f, NewPlayerAdd &t){
    f << t.profile;
    f << t.idPlayer;
    return f;
}

istream& operator >> (istream &f, NewPlayerAdd &t){
    f >> t.profile;
    f >> t.idPlayer;
    return f;
}
