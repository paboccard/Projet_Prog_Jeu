#include "CreateGame.h"

using namespace std;

CreateGame::CreateGame() : Pack(){}

CreateGame::CreateGame(int nbrP) : Pack(){
    idPack = CREATEGAME;
    nbrPlayer = nbrP;
}

void CreateGame::print(ostream &f){
    f << CREATEGAME << " ";
    f << nbrPlayer;
}

void CreateGame::read(istream &f){
    int i;
    f >> i;
    idPack = CREATEGAME;
    f >> nbrPlayer;
}
