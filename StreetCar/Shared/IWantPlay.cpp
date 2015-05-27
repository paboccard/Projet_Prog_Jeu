#include "IWantPlay.h"

using namespace std;

IWantPlay::IWantPlay() : Pack(){}

IWantPlay::IWantPlay(Profile pro) : Pack(){
    profile = pro;
}

void IWantPlay::print(ostream &f){
    f << profile;
}

void IWantPlay::read(istream &f){
    f >> profile;
}
