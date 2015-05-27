#include "PlayedTile.h"

using namespace std;

PlayedTile::PlayedTile() : Pack(){}

PlayedTile::PlayedTile(int idNextP, vector<Tile> tilesPlayed): Pack(){
    idPack = PLAYEDTILE;
    idNextPlayer = idNextP;
    tiles = tilesPlayed;
}

void PlayedTile::print(std::ostream& f){
    f << PLAYEDTILE << " ";
    f << idNextPlayer << " ";
    f << tiles.size() << " ";
    for (unsigned int i = 0; i<tiles.size(); i++)
	f << tiles[i] << " ";
}

void PlayedTile::read(std::istream& f){
    int idP;
    f >> idP;
    idPack = PLAYEDTILE;
    f >> idNextPlayer;
    int nbInVectorTiles;
    f >> nbInVectorTiles;
    tiles.clear();
    for (int i = 0; i< nbInVectorTiles; i++){
	Tile tileTmp;
	f >> tileTmp;
	tiles.push_back(tileTmp);
    }
}
