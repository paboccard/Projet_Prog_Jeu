#include "Player.h"

using namespace std;

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

/*s1 plus petit que s2 ?*/
bool operator<(Stroke const &s1, Stroke const &s2){
	if(s1.tile1 < s2.tile1)
		return true;
	else if (s1.tile1 == s2.tile1 && s1.turn1 < s2.turn1)
		return true;
	else if (s1.tile1 == s2.tile1 && s1.turn1 == s2.turn1 && s1.tile2 < s2.tile2)
		return true;
	else if (s1.tile1 == s2.tile1 && s1.turn1 == s2.turn1 && s1.tile2 == s2.tile2 && s1.turn2 < s2.turn2)
		return true;
	else 
		return false;
 }

bool operator==(Stroke &s1, Stroke &s2){
	return s1.tile1 == s2.tile1 && s1.turn1 == s2.turn1 && s1.tile2 == s2.tile2 && s1.turn2 == s2.turn2 ;
 }

ostream& operator << (std::ostream &f, Stroke &s){

	f << s.tile1 << " " << s.turn1 << " " << s.tile2 << " " << s.turn2;
    return f;
}

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

set<Stroke> Player::strokePossible(){

	set<Stroke> allStroke;
	set<Stroke> result;
	pair<set<Stroke>::iterator,bool> ret;

	int a = 0, b=1;
	int turnA = 0;
	int turnB = 0;
	Stroke s;
	Stroke r;
	
	while(a < 5){
		
		if(a==b) b++;
		
		if(b == 5){
			b=0;
			a++;
		}
		if(a==5) break;

		s.tile1 = hand[a].type;
		s.turn1 = turnA;
		s.tile2 = hand[b].type;
		s.turn2 = turnB;
		
		ret = allStroke.insert(s);
		
		 if (ret.second!=false){
			r.tile1 = a;
			r.turn1 = turnA;
			r.tile2 = b;
			r.turn2 = turnB;
			result.insert(r) ;
		 }
		
		 turnB++;
		
		if(turnB == 4){
			turnB = 0; //Retour rotation initiale
			turnA++;
		}
		
		if(turnA == 4) {
			turnA=0;
			b++;
		}
	}
	return result;
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
