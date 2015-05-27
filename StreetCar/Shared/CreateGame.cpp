#include "CreateGame.h"

using namespace std;

CreateGame::CreateGame() : Pack(){}

CreateGame::CreateGame(Profile h, int nbrP) : Pack(){
    idPack = CREATEGAME;
    host = h;
    nbrPlayer = nbrP;
}

void CreateGame::print(ostream &f){
    f << CREATEGAME << " ";
    f << host << " ";
    f << nbrPlayer;
}

void CreateGame::read(istream &f){
    int i;
    f >> i;
    idPack = CREATEGAME;
    f >> host;
    f >> nbrPlayer;
}
