#include "PilePlayer.h"

using namespace std;

PilePlayer::PilePlayer() : Pack(PILEPLAYER) {}

PilePlayer::PilePlayer(int idP, int idNextP, std::vector<Tile> tilesPiled, std::vector<int> idxTile) : Pack(PILEPLAYER){
	idPlayer = idP;
	idNextPlayer = idNextP;
	this->tilesPiled = tilesPiled;
	this->idxTiles = idxTile;
}

void PilePlayer::print(std::ostream& f){
	Pack::print(f);
	f << idPlayer << " ";
	f << idNextPlayer << " ";
	for (unsigned int i = 0; i<tilesPiled.size(); i++)
		f << tilesPiled[i] << " ";
	f << idxTiles.size() << " ";
	for (unsigned int i = 0; i<idxTiles.size(); i++)
		f << idxTiles[i] << " ";
}

void PilePlayer::read(std::istream& f){
	f >> idPlayer;
	f >> idNextPlayer;
	int nbInVectorTiles;
	f >> nbInVectorTiles;
	tilesPiled.clear();
	idxTiles.clear();
	for (int i = 0; i< nbInVectorTiles; i++){
		Tile tileTmp;
		f >> tileTmp;
		tilesPiled.push_back(tileTmp);
	}
	for (int i = 0; i< nbInVectorTiles; i++){
		int idxT;
		f >> idxT;
		idxTiles.push_back(idxT);
	}
}
