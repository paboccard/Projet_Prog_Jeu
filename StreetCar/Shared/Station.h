#ifndef STATION_H
#define STATION_H
#include "Square.h"
#include "Tile.h"

class Station: public Square {
	public:
		Station(idTile t, int x, int y);
		~Station();

		bool isLinked();
		Tile* getTile();

		bool getAccess(Orientation);
		bool canChange(Square*);
		void rotate(int);
		void print();

	private:
		Tile* linked;

};

#endif
