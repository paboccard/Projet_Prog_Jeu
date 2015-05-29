#include "CreateGame.h"

using namespace std;

CreateGame::CreateGame() : Pack(CREATEGAME){}

CreateGame::CreateGame(int nbrP) : Pack(CREATEGAME){
    nbrPlayer = nbrP;
}

void CreateGame::print(ostream &f){
    Pack::print(f);
    f << nbrPlayer;
}

void CreateGame::read(istream &f){
    
    f >> nbrPlayer;
}
