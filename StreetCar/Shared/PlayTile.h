#ifndef PLAYTILE_H
#define PLAYTILE_H

#include "Pack.h"
#include "Utils.h"
#include "Tile.h"
#include <iostream>
#include <vector>
#include <fstream>

class PlayTile : public Pack{

	public:
		
		int idPlayer;
		Tile *tiles[NBR_TILE_MAX];
		int idxHand[NBR_TILE_MAX];

		PlayTile();
		PlayTile(int idP, Tile *tilesToPlay[], int idTilePlay[]);
		~PlayTile();

		void print(std::ostream& f);
		void read(std::istream& f);
		
		PlayTile& operator = (PlayTile const & t);

		friend std::ostream& operator << (std::ostream &f, PlayTile &t){
			t.print(f);
			return f;
		};
		friend std::istream& operator >> (std::istream &f, PlayTile &t){
			t.read(f);
			return f;
		};

};

#endif
