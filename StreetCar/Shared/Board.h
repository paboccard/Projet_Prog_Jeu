#ifndef BOARD_H
#define BOARD_H

#include "Square.h"
#include "Tile.h"
#include "Stop.h"

using namespace std;

class Board
{
public:
	
	Board();
	
	void whichTerminus(int line, Point term[2][2]);
	
	// GET/SET board
	Square get(int line, int row);
	void set(int line, int row, Tile t);
	
	// GET/SET station
	Point get(int numStation);
	
	bool putPossible(int line, int row, Tile t);

private:
	Square board[14][14];
	Point station[12];

	bool adjacentNorthPossible(Tile a, Square b);
	bool adjacentSouthPossible(Tile a, Square b);
	bool adjacentEastPossible(Tile a, Square b);
	bool adjacentWestPossible(Tile a, Square b);
};

#endif
