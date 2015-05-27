#include "PlayedTile.h"

using namespace std;

PlayedTile::PlayedTile() : Pack(){}

PlayedTile::PlayedTile(vector<Tile> tilesPlayed): Pack(){
    idPack = PLAYEDTILE;
    tiles = tilesPlayed;
}

void PlayedTile::print(std::ostream& f){
    f << PLAYEDTILE << " ";
    f << tiles.size() << " ";
    for (unsigned int i = 0; i<tiles.size(); i++)
	f << tiles[i] << " ";
}

void PlayedTile::read(std::istream& f){
    int idP;
    f >> idP;
    idPack = PLAYEDTILE;
    int nbInVectorTiles;
    f >> nbInVectorTiles;
    tiles.clear();
    for (int i = 0; i< nbInVectorTiles; i++){
	Tile tileTmp;
	f >> tileTmp;
	tiles.push_back(tileTmp);
    }
}
