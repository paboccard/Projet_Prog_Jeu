#include "PlayedTravel.h"

using namespace std;

PlayedTravel::PlayedTravel(int idP, Travel travelOfTram): Pack(){
    idPack = PLAYEDTRAVEL;
    idNextPlayer = idP;
    tram = travelOfTram;
}

ostream& operator << (std::ostream &f, PlayedTravel &t){
    f << PLAYEDTRAVEL << " ";
    f << t.idNextPlayer << " ";
    if (t.tram.isInTerminus)
	f << 1 << " ";
    else 
	f << 0 << " ";
    f << t.tram.prevTile << " " << t.tram.curTile << " ";
    f << t.tram.origin << " ";
    return f;
}

istream& operator >> (std::istream &f, PlayedTravel &t){
    int idP;
    f >> idP;
    t.idPack = PLAYTRAVEL;
    f >> t.idNextPlayer;
    int isTerminus;
    f >> isTerminus;
    if (isTerminus)
	t.tram.isInTerminus = true;
    else 
	t.tram.isInTerminus = false;
    Tile tile;
    f >> tile;
    t.tram.prevTile = tile;
    f >> tile;
    t.tram.curTile = tile;
    int ori;
    f >> ori;
    switch(ori){
    case 0:
	t.tram.origin = WEST;
	break;
    case 1:
	t.tram.origin = SOUTH;
	break;
    case 2:
	t.tram.origin = EAST;
	break;
    case 3:
	t.tram.origin = NORTH;
	break;
    }
    return f;
}
