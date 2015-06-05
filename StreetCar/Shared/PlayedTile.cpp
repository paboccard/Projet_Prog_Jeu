#include "PlayedTile.h"

using namespace std;

PlayedTile::PlayedTile() : Pack(PLAYEDTILE){}

/*
PlayedTile::PlayedTile(vector<Tile*> tilesPlayed, vector<int> idxT): Pack(PLAYEDTILE){
	tiles = tilesPlayed;
	idxTiles = idxT;
}
*/
PlayedTile::PlayedTile(Tile *t[NBR_TILE_MAX], int idx[NBR_TILE_MAX]) : Pack(PLAYEDTILE) { 
	for (int i = 0; i < NBR_TILE_MAX; i++){
		tiles[i] = t[i];
		idxHand[i] = idx[i];
	}
}

void PlayedTile::print(std::ostream& f){
	Pack::print(f);
	/*
	f << tiles.size() << " ";
	for (unsigned int i = 0; i<tiles.size(); i++)
		f << *tiles[i] << " ";
	f << idxTiles.size() << " ";
	for (unsigned int i = 0; i<idxTiles.size(); i++)
		f << idxTiles[i] << " ";
	*/
	for (int i = 0; i < NBR_TILE_MAX; i ++)
		f << *tiles[i] << " " << idxHand[i] << " ";
}

void PlayedTile::read(std::istream& f){
	/*
	int nbInVectorTiles;
	f >> nbInVectorTiles;
	tiles.clear();
	idxTiles.clear();
	for (int i = 0; i< nbInVectorTiles; i++){
		Tile* tileTmp = new Tile();
		f >> *tileTmp;
		tiles.push_back(tileTmp);
	}
	for (int i = 0; i< nbInVectorTiles; i++){
		int idxT;
		f >> idxT;
		idxTiles.push_back(idxT);
	}
	*/
	for (int i = 0; i < NBR_TILE_MAX; i ++) {
		Tile *tileTmp = new Tile();
		f >> *tileTmp;
		tiles[i] = tileTmp;
		f >> idxHand[i];
	}
}
