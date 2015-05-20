#include "Utils.h"
#include "Board.h"
#include "Tile.h"
#include "Stop.h"

using namespace std;

Board::Board(){
	
	// all tiles are empty
	for(int i; i<12; i++)
		for(int j; j<12; j++)
			board[i][j] = new Tile();
	
	terminus[0][0].x=9;
	terminus[0][0].y=0;
	terminus[0][1].x=5;
	terminus[0][1].y=11;

	terminus[1][0].x=1;
	terminus[1][0].y=11;
	terminus[1][1].x=5;
	terminus[1][1].y=0;

	terminus[2][0].x=1;
	terminus[2][0].y=0;
	terminus[2][1].x=9;
	terminus[2][1].y=11;

	terminus[3][0].x=0;
	terminus[3][0].y=1;
	terminus[3][1].x=11;
	terminus[3][1].y=5;

	terminus[4][0].x=0;
	terminus[4][0].y=5;
	terminus[4][1].x=11;
	terminus[4][1].y=9;

	terminus[5][0].x=0;
	terminus[5][0].y=9;
	terminus[5][1].x=11;
	terminus[5][1].y=1;
}

Square Board::get(int x, int y)
{
	return board[x][y];
}
  
void Board::set(int x, int y, Square sq)
{
	board[x][y] = sq;
}

bool Board::putPossible(int line, int row, Square t)
{
	bool res;
		
	// The destination must be empty
	if(board[line][row].isEmpty()) res = true;
	else res = false;
		
	// Square North
	if(line != 0) res = res && adjacentNorthPossible(t, board[line-1][row]);
	else res = res && connectedToTerminus(t, NORTH);
		
	// Square South
	if(line != 11) res = res && adjacentSouthPossible(t, board[line+1][row]);
	else res = res && connectedToTerminus(t, SOUTH);
		
	// Square East
	if(row != 11) res = res && adjacentEastPossible(t, board[line][row+1]);
	else res = res && connectedToTerminus(t, EAST);
		
	// Square West
	if(row != 0) res = res && adjacentWestPossible(t, board[line][row-1]);
	else res = res && connectedToTerminus(t, WEST);
		
	return res;
}

bool Board::connectedToTerminus(Tile t, int direction){
	
	bool res;
	
	switch direction {
		case NORTH:
			res = (t.coordinates.x == Terminus[0][0].x) || (t.coordinates.x == Terminus[1][1].x) || (t.coordinates.x == Terminus[2][0].x);
			res = res && (t.access[NORTH] == OBLIGATORY);
			break;
		case EAST:
			res = (t.coordinates.y == Terminus[3][1].y) || (t.coordinates.y == Terminus[4][1].y) || (t.coordinates.y == Terminus[5][0].y);
			res = res && (t.access[EAST] == OBLIGATORY);
			break;
		case WEST:
			res = (t.coordinates.y == Terminus[3][0].y) || (t.coordinates.y == Terminus[4][0].y) || (t.coordinates.y == Terminus[5][1].y);
			res = res && (t.access[WEST] == OBLIGATORY);
			break;
		case SOUTH:
			res = (t.coordinates.x == Terminus[0][1].x) || (t.coordinates.x == Terminus[1][0].x) || (t.coordinates.x == Terminus[2][1].x);
			res = res && (t.access[SOUTH] == OBLIGATORY);
			break;
		default:
			cout << "FATAL ERROR: File Board.cpp function connectedToTerminus: direction unknown" << endl;
			res = false;
			break;
	}
}

/*We want play tile a
 * a
 * --
 * b
 * 
 * if b is an empty tile return true
 * else if b is a tile not empty, or a stop, we verify the connections with a.access[NORTH] and b.access[SOUTH] 
 */
bool Board::adjacentNorthPossible(Tile a, Square b){
	return b.isEmpty || (a.access[NORTH] xor b.access[SOUTH]);
}

bool Board::adjacentSouthPossible(Tile a, Square b){
	return b.isEmpty || (a.access[SOUTH] xor b.access[NORTH]);
}

bool Board::adjacentEastPossible(Tile a, Square b){
	return b.isEmpty || (a.access[EAST] xor b.access[WEST]);
}

bool Board::adjacentWestPossible(Tile a, Square b){
	return b.isEmpty || (a.access[WEST] xor b.access[EAST]);
}