#include "Player.h"

Player::Player() : profile("inconnu",-1){
	
    hand[0] = Tile(Empty, -1);
    hand[1] = Tile(Empty, -1);
    hand[2] = Tile(Empty, -1);
    hand[3] = Tile(Empty, -1);
    hand[4] = Tile(Empty, -1);
    line = 0;
	
    isTravelling = false;
	travel.isInTerminus = false;
    travel.curTile = Tile(Empty, -1);
    travel.prevTile = Tile(Empty, -1);
    travel.origin = NORTH;
}

bool Player::handIsEmpty(){
	int i = 0;
	while(i < 5 && hand[i].type == EmptyHand) i++;
	
	return i == 5;
}