#ifndef BOARD_H
#define BOARD_H

#include "Square.h"
#include "Tile.h"
#include "Station.h"
#include <fstream>

#define BOARD_SIZE 14
#define NBR_STATION 12

using namespace std;

class Board
{
	public:

		Board(int s = 0, int nb = 0);

		~Board();

		void free();

		void whichTerminus(int line, Point term[2][2]);

		// GET/SET board
		Square* get(int row, int column);
		void set(int row, int column, Square *t);

		int getSize();
		void setSize(int s, int nb);
		int getNbrStation();
		Station *getStation(idTile i);

		// GET/SET station

		bool putPossible(Point p, Tile *t);
		bool putPossible(int row, int column, Tile *t);
		bool changePossible(Tile *t1, Tile *t2);

		// returns the stop next to the given index or NULL if there is no stops
		Station* nextToStop(int row, int column);

		//void copy(Board copy);
		void printConsole();
		void read(std::istream &f);

		void initRandom();

	private:
		int size;
		int nbrStation;
		Square* **board;	//double table of square
		Station* *stations;
		bool adjacentPossible(Tile *a, Square *b, Orientation o);
/*
		bool adjacentNorthPossible(Tile a, Square *b);
		bool adjacentSouthPossible(Tile a, Square *b);
		bool adjacentEastPossible(Tile a, Square *b);
		bool adjacentWestPossible(Tile a, Square *b);
		*/
	protected:
		void setSquare(Square *s);
		void changeSquare(Square *s);
};

#endif
