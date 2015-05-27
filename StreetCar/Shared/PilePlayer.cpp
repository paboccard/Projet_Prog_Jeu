#include "PilePlayer.h"

using namespace std;

PilePlayer::PilePlayer() : Pack() {}

PilePlayer::PilePlayer(int idP, Tile myHand[5]) : Pack(){
    idPack = PILEPLAYER; 
    idPlayer = idP;
    for (int i = 0; i<5; i++)
	hand[i] = myHand[i];
}

void PilePlayer::print(std::ostream& f){
    f << PILEPLAYER << " ";
    f << idPlayer << " ";
    for (int i = 0; i<5; i++)
	f << hand[i] << " ";
}

void PilePlayer::read(std::istream& f){
    int idP;
    f >> idP;
    idPack = PILEPLAYER;
    f >> idPlayer;
    for (int i = 0; i<5; i++){
	Tile tileTmp;
	f >> tileTmp;
	hand[i] = tileTmp;
    }
}
