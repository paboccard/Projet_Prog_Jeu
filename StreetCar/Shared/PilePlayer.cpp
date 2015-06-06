#include "PilePlayer.h"

using namespace std;

PilePlayer::PilePlayer() : Pack(PILEPLAYER) {}

PilePlayer::PilePlayer(int idP, int idNextP, std::vector<Tile*> tilesPiled, std::vector<int> idxTile) : Pack(PILEPLAYER){
	idPlayer = idP;
	idNextPlayer = idNextP;
	this->tilesPiled = tilesPiled;
	this->idxTiles = idxTile;
}

PilePlayer::~PilePlayer()
{
	cout << "Destruct PilePlayer" << endl;
	for (int i = 0; i < tilesPiled.size(); i ++)
		delete tilesPiled[i];
}

void PilePlayer::print(std::ostream& f){
	Pack::print(f);
	f << idPlayer << " ";
	f << idNextPlayer << " ";
	f << tilesPiled.size() << " ";
	for (unsigned int i = 0; i<tilesPiled.size(); i++)
		f << *tilesPiled[i] << " ";
	// the two vector have the same size
	//f << idxTiles.size() << " ";
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
		Tile *tileTmp = new Tile;
		f >> *tileTmp;
		tilesPiled.push_back(tileTmp);
	}

	for (int i = 0; i< nbInVectorTiles; i++){
		int idxT;
		f >> idxT;
		idxTiles.push_back(idxT);
	}
}
