#include "Utils.h"

public class Board {
  
	private Tile[12][12] board;
  
	public Tile get(int x, int y){
		return board[x][y];
	}
  
	public void set(int x, int y, Tile t){
		board[x][y] = t;
	}
	
	public bool putPossible(int x, int y, Tile t){
		return true;
	}
}