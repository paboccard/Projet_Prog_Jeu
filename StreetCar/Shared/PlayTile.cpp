#include "PlayTile.h"

using namespace std;

PlayTile::PlayTile(int idP, Tile TilesToPlay[2], int idTilePlay[2]) : Pack(){
    idPack = PLAYTILE;
    idPlayer = idP;

    for (int i = 0; i<2; i++)
	tiles[i] = TilesToPlay[i];

    for (int i = 0; i<2; i++)
        idxHand[i] = idTilePlay[i];
}

ostream& operator << (std::ostream &f, PlayTile &t){
    f << PLAYTILE << " ";
    f << t.idPlayer << " ";
    for (int i = 0; i<2; i++)
        f << t.tiles[i] << " ";
    for (int i = 0; i<2; i++)
        f << t.idxHand[i] << " ";
    return f;
}

istream& operator >> (std::istream &f, PlayTile &t){
    int idP;
    f >> idP;
    t.idPack = PLAYTILE;
    f >> t.idPlayer;
    for (int i = 0; i<2; i++){
	Tile tileTmp;
	f >> tileTmp;
	t.tiles[i] = tileTmp;
    }
    for (int i = 0; i<2; i++){
	int idH;
	f >> idH;
	t.idxHand[i] = idH;
    }
    return f;
}
