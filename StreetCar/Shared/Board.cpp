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
	terminus[0][1].x=5;
	terminus[0][0].y=0;
	terminus[0][1].y=11;

	terminus[1][0].x=1;
	terminus[1][1].x=5;
	terminus[1][0].y=11;
	terminus[1][1].y=0;

	terminus[2][0].x=1;
	terminus[2][1].x=9;
	terminus[2][0].y=0;
	terminus[2][1].y=11;

	terminus[3][0].x=0;
	terminus[3][1].x=11;
	terminus[3][0].y=1;
	terminus[3][1].y=5;

	terminus[4][0].x=0;
	terminus[4][1].x=11;
	terminus[4][0].y=5;
	terminus[4][1].y=9;

	terminus[5][0].x=0;
	terminus[5][1].x=11;
	terminus[5][0].y=9;
	terminus[5][1].y=1;
}

Tile Board::get(int x, int y)
{
	return board[x][y];
}
  
void Board::set(int x, int y, Tile t)
{
	board[x][y] = t;
}

bool Board::putPossible(int line, int row, Tile t)
{
		
	bool res;
		
	// The destination must be empty
	if(board[line][row].isEmpty()) res = true;
	else res = false;
		
	// Square North
	if(line != 0) res = res && adjacentPossible(t, board[line-1][row]);
	else res = res && (t.access[NORTH] == IMPOSSIBLE);
		
	// Square South
	if(line != 11) res = res && adjacentPossible(t, board[line+1][row]);
	else res = res && (t.access[SOUTH] == IMPOSSIBLE);
		
	// Square East
	if(row != 11) res = res && adjacentPossible(t, board[line][row+1]);
	else res = res && (t.access[EAST] == IMPOSSIBLE);
		
	// Square West
	if(row != 0) res = res && adjacentPossible(t, board[line][row-1]);
	else res = res && (t.access[WEST] == IMPOSSIBLE);
		
	return res;
}

bool Board::adjacentPossible(Tile a, Tile b){
	return true;
}