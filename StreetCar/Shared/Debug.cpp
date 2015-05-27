#include "Debug.h"

using namespace std;

Debug::Debug() : Pack(){}

Debug::Debug(string deb) : Pack(){
    idPack = DEBUG;
    debug = deb;
}

void Debug::print(ostream &f){
    f << DEBUG << " ";
    f << debug;
}

void Debug::read(istream &f){
    int i;
    f >> i;
    idPack = DEBUG;
    f >> debug;
}
