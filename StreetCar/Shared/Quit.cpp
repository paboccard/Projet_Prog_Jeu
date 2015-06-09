#include "Quit.h"

using namespace std;

Quit::Quit() : Pack(QUIT){
}

Quit::Quit(int numG) : Pack(QUIT){
    numGame = numG;
}


void Quit::print(ostream &f){
    Pack::print(f);
    f << numGame << " ";
}

void Quit::read(istream &f){
    f >> numGame;
}
