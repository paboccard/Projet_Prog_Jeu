#include "PlayTile.h"

using namespace std;

PlayTile::PlayTile() : Pack(){}

PlayTile::PlayTile(int idP, Tile TilesToPlay[2], int idTilePlay[2]) : Pack(){
    idPack = PLAYTILE;
    idPlayer = idP;

    for (int i = 0; i<2; i++)
	tiles[i] = TilesToPlay[i];

    for (int i = 0; i<2; i++)
        idxHand[i] = idTilePlay[i];
}

void PlayTile::print(std::ostream& f){
    f << PLAYTILE << " ";
    f << idPlayer << " ";
    for (int i = 0; i<2; i++)
        f <<tiles[i] << " ";
    for (int i = 0; i<2; i++)
        f << idxHand[i] << " ";
}

void PlayTile::read(std::istream& f){
    int idP;
    f >> idP;
    idPack = PLAYTILE;
    f >> idPlayer;
    for (int i = 0; i<2; i++){
	Tile tileTmp;
	f >> tileTmp;
	tiles[i] = tileTmp;
    }
    for (int i = 0; i<2; i++){
	int idH;
	f >> idH;
	idxHand[i] = idH;
    }
}
