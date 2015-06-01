#include "PlayedTile.h"

using namespace std;

PlayedTile::PlayedTile() : Pack(PLAYEDTILE){}

PlayedTile::PlayedTile(vector<Tile> tilesPlayed, vector<int> idxT): Pack(PLAYEDTILE){
    tiles = tilesPlayed;
    idxTiles = idxT;
}

void PlayedTile::print(std::ostream& f){
    Pack::print(f);
    f << tiles.size() << " ";
    for (unsigned int i = 0; i<tiles.size(); i++)
	f << tiles[i] << " ";
    f << idxTiles.size() << " ";
    for (unsigned int i = 0; i<idxTiles.size(); i++)
	f << idxTiles[i] << " ";
}

void PlayedTile::read(std::istream& f){
    int nbInVectorTiles;
    f >> nbInVectorTiles;
    tiles.clear();
    idxTiles.clear();
    for (int i = 0; i< nbInVectorTiles; i++){
	Tile tileTmp;
	f >> tileTmp;
	tiles.push_back(tileTmp);
    }
    for (int i = 0; i< nbInVectorTiles; i++){
	int idxT;
	f >> idxT;
	idxTiles.push_back(idxT);
    }
}
