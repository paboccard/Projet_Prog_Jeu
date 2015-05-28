#include "Debug.h"

using namespace std;

Debug::Debug() : Pack(DEBUG){}

Debug::Debug(string deb) : Pack(DEBUG){
    idPack = DEBUG;
    debug = deb;
}

void Debug::print(ostream &f){
    Pack::print(f);
    f << debug;
}

void Debug::read(istream &f){
    f >> debug;
}
