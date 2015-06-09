#include "Launch.h"

using namespace std;

Launch::Launch() : Pack(LAUNCH){
}

Launch::Launch(int numG) : Pack(LAUNCH){
    numGame = numG;
}


void Launch::print(ostream &f){
    Pack::print(f);
    f << numGame << " ";
}

void Launch::read(istream &f){
    f >> numGame;
}

