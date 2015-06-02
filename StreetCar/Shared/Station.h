#ifndef STATION_H
#define STATION_H
#include "Square.h"
#include "Tile.h"

class Station: public Square {
	public:
		Station(idTile t, int x, int y);
		~Station();

		bool isLinked();
//		Tile* getTile();
		void setOrientation(Orientation o);
		Orientation getOrientation();

		bool getAccess(Orientation);
		bool canChange(Square*);
		void print();
		void change(Square *s);

	private:
		bool linked;
		Orientation orientation;
};

#endif
