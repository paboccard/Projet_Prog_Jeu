#include "PlayTile.h"

using namespace std;

PlayTile::PlayTile() : Pack(PLAYTILE){}

PlayTile::PlayTile(int idP, Tile* TilesToPlay[2], int idTilePlay[2]) : Pack(PLAYTILE){
    idPlayer = idP;

    for (int i = 0; i<2; i++){
        tiles[i] = TilesToPlay[i];
		cout << "tiles to play : " << (int) tiles[i]->getType() << endl;
    }

    for (int i = 0; i<2; i++)
        idxHand[i] = idTilePlay[i];
}

void PlayTile::print(std::ostream& f){
    Pack::print(f);
    f << idPlayer << " ";
    for (int i = 0; i<2; i++)
        f <<tiles[i] << " ";
    for (int i = 0; i<2; i++)
        f << idxHand[i] << " ";
}

void PlayTile::read(std::istream& f){
    f >> idPlayer;
    for (int i = 0; i<2; i++){
	Tile *tileTmp = new Tile();
	f >> *tileTmp;
	tiles[i] = tileTmp;
    }
    for (int i = 0; i<2; i++){
	int idH;
	f >> idH;
	idxHand[i] = idH;
    }
}
