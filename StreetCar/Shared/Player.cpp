#include "Player.h"

using namespace std;

Player::Player(){}


ostream& operator << (std::ostream &f, Travel &t){
    if (t.isInTerminus)
	f << 1 << " ";
    else 
	f << 0 << " ";
    f << t.prevTile << " " << t.curTile << " ";
    f << t.origin << " ";

    return f;
    // switch(t.origin){
    // case WEST:
    // 	f << 0 << " ";
    // 	break;
    // case SOUTH:
    // 	f << 1 << " ";
    // 	break;
    // case EAST:
    // 	f << 2 << " ";
    // 	break;
    // case NORTH:
    // 	f << 3 << " ";
    // 	break;
    // }  
}

istream& operator >> (std::istream &f, Travel &t){
    int isTerminus;
    f >> isTerminus;
    if (isTerminus)
	t.isInTerminus = true;
    else 
	t.isInTerminus = false;
    Tile tile;
    f >> tile;
    t.prevTile = tile;
    f >> tile;
    t.curTile = tile;
    int ori;
    f >> ori;
    switch(ori){
    case 0:
	t.origin = WEST;
	break;
    case 1:
	t.origin = SOUTH;
	break;
    case 2:
	t.origin = EAST;
	break;
    case 3:
	t.origin = NORTH;
	break;
    }
    return f;
}
