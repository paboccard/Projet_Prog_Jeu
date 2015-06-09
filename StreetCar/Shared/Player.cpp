#include "Player.h"

using namespace std;

Player::Player() : profile("inconnu",-1, 0){
	for (int i = 0; i < 5; i ++)
		hand[i] = new Tile(Empty, -1);

	line = 0;
	
	isTravelling = false;
	travel.isInTerminus = false;
	travel.curTile = new Tile(Empty, -1);
	travel.prevTile = new Tile(Empty, -1);
	travel.origin = NORTH;
}

bool Player::handIsEmpty(){
	int i = 0;
	while(i < 5 && hand[i]->getType() == EmptyHand)
		i++;
	
	return i == 5;
}

int Player::getMyIdPlayer(){
    return myIdPlayer;
}

Tile** Player::getHand(){
    return hand;
}

Tile* Player::getHand(int position){
    return hand[position];
}

int Player::getLine(){
	return line;
}

int Player::getStopCard()
{
	return stopCard;
}

bool Player::getTravelling(){
    return isTravelling;
}

Travel* Player::getTravel(){
    return &travel;
}

Profile Player::getProfile(){
    return profile;
}

vector<Station*> Player::getItinerary(){
    return itinerary;
}

void Player::setMyIdPlayer(int i){
    myIdPlayer = i;
}

void Player::setHand(Tile* h[5]){
    for (int i = 0; i < 5; i++)
		hand[i] = h[i];
}

void Player::setHand(Tile h[5]){
    for (int i = 0; i < 5; i++)
		*hand[i] = h[i];
}

void Player::setHand(Tile *h,int position){
	//delete hand[position];
    cout << "********** modification of the hand of the player : " << getMyIdPlayer() << endl;
    cout << " old type : " << hand[position]->getType() << endl;
    cout << " new type : " << h->getType() << endl;
    
    h->print();
    *hand[position] = *h;
    

}

void Player::setLine(int l){
	line = l;
}

void Player::setStopCard(int s)
{
	stopCard = s;
}

void Player::setTravelling(bool travelling){
    isTravelling = travelling;
}

void Player::setProfile(Profile p){
    profile = p;
}

void Player::setItinerary(vector<Station*> it){
    itinerary = it;
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

		s.tile1 = hand[a]->getType();
		s.turn1 = turnA;
		s.tile2 = hand[b]->getType();
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
	Tile *tile = new Tile();
	f >> *tile;
	t.prevTile = tile;
	tile = new Tile();
	f >> *tile;
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

void Player::printHand(){
	Tile t;
	cout << "Main de player: "<< endl;
	t = *hand[0];
	t.print();
	t = *hand[1];
	t.print();
	t = *hand[2];
	t.print();
	t = *hand[3];
	t.print();
	t = *hand[4];
	t.print();
}

ostream& operator << (ostream &f, Player &t){
  f << t.myIdPlayer << " " << t.profile << " ";
  for (int i = 0; i<5; i++)
    f << *t.hand[i] << " ";
  f << t.isTravelling << " " << t.travel << " " << t.line << " " << t.stopCard << " ";
  f << t.itinerary.size();
  for (unsigned int i = 0; i<t.itinerary.size(); i++)
    f << t.itinerary[i] << " ";
  
  return f;
}
istream& operator >> (istream &f, Player &t){
  f >> t.myIdPlayer ;
  f >> t.profile ;
  for (int i = 0; i<5; i++){
    Tile tile;
    f >> tile;
    t.hand[i] = &tile;
  }
  f >> t.isTravelling;
  f >> t.travel;
  f >> t.line;
  f >> t.stopCard;
  int nbr;
  f >> nbr;
  for (int i = 0; i<nbr; i++){
    Station s;
    f >> s;
    t.itinerary.push_back(&s);
  }

  return f;
}

