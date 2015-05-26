#include "PilePlayer.h"

using namespace std;

PilePlayer::PilePlayer(int idP, Tile myHand[5]) : Pack(){
    idPack = PILEPLAYER; 
    idPlayer = idP;
    for (int i = 0; i<5; i++)
	hand[i] = myHand[i];
}

ostream& operator << (std::ostream &f, PilePlayer &t){
    f << PILEPLAYER << " ";
    f << t.idPlayer << " ";
    for (int i = 0; i<5; i++)
	f << t.hand[i] << " ";
    return f;
}

istream& operator >> (std::istream &f, PilePlayer &t){
    int idP;
    f >> idP;
    t.idPack = PILEPLAYER;
    f >> t.idPlayer;
    for (int i = 0; i<5; i++){
	Tile tileTmp;
	f >> tileTmp;
	t.hand[i] = tileTmp;
    }
    return f;
}
