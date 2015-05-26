#include "PlayedTile.h"

using namespace std;

PlayedTile::PlayedTile() : Pack(){}

PlayedTile::PlayedTile(int idNextP, vector<Tile> tilesPlayed): Pack(){
    idPack = PLAYEDTILE;
    idNextPlayer = idNextP;
    tiles = tilesPlayed;
}

ostream& operator << (std::ostream &f, PlayedTile &t){
    f << PLAYEDTILE << " ";
    f << t.idNextPlayer << " ";
    f << t.tiles.size() << " ";
    for (unsigned int i = 0; i<t.tiles.size(); i++)
	f << t.tiles[i] << " ";
    return f;
}

istream& operator >> (std::istream &f, PlayedTile &t){
    int idP;
    f >> idP;
    t.idPack = PLAYEDTILE;
    f >> t.idNextPlayer;
    int nbInVectorTiles;
    f >> nbInVectorTiles;
    t.tiles.clear();
    for (int i = 0; i< nbInVectorTiles; i++){
	Tile tileTmp;
	f >> tileTmp;
	t.tiles.push_back(tileTmp);
    }
    return f;
}
