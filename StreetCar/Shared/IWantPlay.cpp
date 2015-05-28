#include "IWantPlay.h"

using namespace std;

IWantPlay::IWantPlay() : Pack(IWANTPLAY){}

IWantPlay::IWantPlay(Profile pro) : Pack(IWANTPLAY){
    profile = pro;
}

void IWantPlay::print(ostream &f){
    Pack::print(f);
    f << profile;
}

void IWantPlay::read(istream &f){
    f >> profile;
}
