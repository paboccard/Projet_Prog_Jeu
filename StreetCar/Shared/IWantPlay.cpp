#include "IWantPlay.h"

using namespace std;

IWantPlay::IWantPlay(Profile pro) : Pack(){
    profile = pro;
}

ostream& operator << (ostream &f, IWantPlay &t){
    f << t.profile;
    return f;
}

istream& operator >> (istream &f, IWantPlay &t){
    f >> t.profile;
    return f;
}
