#include "StartGame.h"

using namespace std;

StartGame::StartGame() : Pack(STARTGAME){
}

void StartGame::print(ostream &f){
    Pack::print(f);
}

void StartGame::read(istream &f){}
