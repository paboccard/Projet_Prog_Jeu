#include "PilePlayer.h"

using namespace std;

PilePlayer::PilePlayer() : Pack(PILEPLAYER) {}

PilePlayer::PilePlayer(int idP, int idNextP, Tile myHand[5]) : Pack(PILEPLAYER){
    idPlayer = idP;
    idNextPlayer = idNextP;
    for (int i = 0; i<5; i++)
	hand[i] = myHand[i];
}

void PilePlayer::print(std::ostream& f){
    Pack::print(f);
    f << idPlayer << " ";
    f << idNextPlayer << " ";
    for (int i = 0; i<5; i++)
	f << hand[i] << " ";
}

void PilePlayer::read(std::istream& f){
    f >> idPlayer;
    f >> idNextPlayer;
    for (int i = 0; i<5; i++){
	Tile tileTmp;
	f >> tileTmp;
	hand[i] = tileTmp;
    }
}
