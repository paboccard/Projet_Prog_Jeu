#include "Quit.h"

using namespace std;

Quit::Quit() : Pack(QUIT){
}

void Quit::print(ostream &f){
    Pack::print(f);
}

void Quit::read(istream &f){}
