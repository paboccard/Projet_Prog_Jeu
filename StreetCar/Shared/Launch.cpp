#include "Launch.h"

using namespace std;

Launch::Launch() : Pack(LAUNCH){
}

void Launch::print(ostream &f){
    Pack::print(f);
}

void Launch::read(istream &f){}
