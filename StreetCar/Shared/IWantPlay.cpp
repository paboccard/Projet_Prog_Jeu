#include "IWantPlay.h"

using namespace std;

IWantPlay::IWantPlay() : Pack(){}

IWantPlay::IWantPlay(Profile pro) : Pack(){
    idPack = IWANTPLAY;
    profile = pro;
}

void IWantPlay::print(ostream &f){
    f << IWANTPLAY << " ";
    f << profile;
}

void IWantPlay::read(istream &f){
    int i;
    f >> i;
    idPack = IWANTPLAY;
    f >> profile;
}
