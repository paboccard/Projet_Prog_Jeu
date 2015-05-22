#include "PlayTile.h"

using namespace std;

PlayTile::PlayTile(int idP, Tile myHand[5], int idTilePlay[2]) : Pack(){
    idPack = PLAYTILE;
    idPlayer = idP;
    for (int i = 0; i<5; i++)
	hand[i] = myHand[i];
    
    for (int i = 0; i<2; i++)
	idHand[i] = idTilePlay[i];
}

ostream& operator << (std::ostream &f, PlayTile &t){
    f << PLAYTILE << " ";
    f << t.idPlayer << " ";
    for (int i = 0; i<5; i++)
	f << t.hand[i] << " ";
    for (int i = 0; i<2; i++)
	f << t.idHand[i] << " ";
    return f;
}

istream& operator >> (std::istream &f, PlayTile &t){
    int idP;
    f >> idP;
    t.idPack = PLAYTILE;
    f >> t.idPlayer;
    for (int i = 0; i<5; i++){
	Tile tileTmp;
	f >> tileTmp;
	t.hand[i] = tileTmp;
    }
    for (int i = 0; i<2; i++){
	int idH;
	f >> idH;
	t.idHand[i] = idH;
    }
    return f;
}
