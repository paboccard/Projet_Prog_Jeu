#include "Tile.h"
#include <iostream>

using namespace std;


Tile::Tile(idTile t, int x, int y, int p) : Square(t, x, y) {

	idPlayer = p;
	turn = 0;
	setType(t);
	access[0] = false;
	access[1] = false;
	access[2] = false;
	access[3] = false;
}

Tile::~Tile()
{
	ways.clear();
}

void Tile::setStop(bool s)
{
	stop = s;
}

bool Tile::canChange(Square *s){
	if(!s->isTile() || tree || getType() == s->getType())
		return false;
	/*
	bool search = true;
	bool search2 ;
	unsigned int j;
	unsigned int i = 0;
	while(search && i != ways.size() ){
		j = 0;
		search2 = false;
		while(!search2 && j != s->ways.size() ){

			search2 = ((ways[i].s1 == t2.ways[j].s1) && (t1.ways[i].s2 == t2.ways[j].s2));
			j++;
		}
		i++;
		search = search2;
	}
	return true;
	*/
	unsigned int i = 0;
	while (i < ways.size() && ((Tile*)s)->haveRail(ways[i]))
		i ++;
	return i < ways.size();

}

void Tile::rotate(int r)
{
	turn = (turn + r )% 4;
	bool temp = access[(WEST+r)%4];
	access[(WEST+r)%4] = access[(NORTH+r)%4];
	access[(NORTH+r)%4] = access[(EAST+r)%4];
	access[(EAST+r)%4] = access[(SOUTH+r)%4];
	access[(SOUTH+r)%4] = temp;

	for(unsigned int i = 0; i < ways.size(); i++){
		ways[i].s1 = (Orientation)((ways[i].s1 + r) % 4);
		ways[i].s2 = (Orientation)((ways[i].s2 + r) % 4);

		if (ways[i].s1 > ways[i].s2) {
			Orientation tmp = ways[i].s1;
			ways[i].s1 = ways[i].s2;
			ways[i].s2 = tmp;
		}
	}
}

bool Tile::haveRail(Rail r)
{
	unsigned int i = 0;
	while (i < ways.size() && ways[i].s1 < r.s1)
		i++;

	return i < ways.size() && ways[i].s1 == r.s1 && ways[i].s2 == r.s2;
}

bool Tile::isStop()
{
	return stop;
}

bool Tile::getAccess(Orientation o)
{
	return access[o];
}

void Tile::print()
{
	Square::print();
	cout << "Access NORTH: " << access[NORTH] << endl;
	cout << "Access SOUTH: " << access[SOUTH] << endl;
	cout << "Access EAST: " << access[EAST] << endl;
	cout << "Access WEST: " << access[WEST] << endl;

	cout << "Number of ways: " << ways.size() << endl;
	for (unsigned int i = 0; i<ways.size(); i++){
		cout << ways[i].s1 << " " << ways[i].s2 << endl;
	}
	cout << "Rotation: " << turn << endl;
	cout << "Type: " << getType() << endl;
	cout << "Players: " << idPlayer << " ";
	cout << "Access: ";
	for (int i = 0; i<4; i++){
		if (access[i])
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}
	cout << endl;
}

ostream& operator << (ostream &f, Tile &t){	
	f << t.tree << " ";

	f << t.ways.size() << " ";
	for (unsigned int i = 0; i<t.ways.size(); i++){
		f << t.ways[i].s1 << " " << t.ways[i].s2 << " ";
	}
	f << t.turn << endl;
	f << (int)t.getType() << endl;
	f << t.idPlayer << " ";
	for (int i = 0; i<4; i++)
		if (t.access[i])
			f << 1 << " ";
		else
			f << 0 << " ";
	return f;
}

istream& operator >> (istream &f, Tile &t){
	Rail r;
	f >> t.tree;

	int nbrT;
	f >> nbrT;
	t.ways.clear();
	for (int i = 0; i<nbrT; i++){
		int s1, s2;
		f >> s1;
		f >> s2;
		r.s1 = (Orientation)s1;
		r.s2 = (Orientation)s2;
		t.ways.push_back(r);
	}

	f >> t.turn;

	int ty;
	f >> ty;
	t.setType((idTile)ty);

	f >> t.idPlayer;
	for (int i = 0; i<4; i++){
		int test;
		f >> test;
		if (test)
			t.access[i] = 1;
		else
			t.access[i] = 0;
	}
	return f;
}

void Tile::setType(idTile id) {
	Square::setType(id);
	ways.clear();
	switch(getType()){
/*
   |
   |
*/
		case Straight:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = NORTH;
			ways[0].s2 = SOUTH;
			break;
/*
  __
	\
*/
		case Curve:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
/*

  __ \__
	\
*/
		case DoubleCurves:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(2);
			ways[0].s1 = NORTH;
			ways[0].s2 = EAST;
			ways[1].s1 = WEST;
			ways[1].s2 = SOUTH;
			break;
/*
	|
  --|--
	|
*/
		case Intersect:
			tree = true;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(2);
			ways[0].s1 = NORTH;
			ways[0].s2 = SOUTH;
			ways[1].s1 = EAST;
			ways[1].s2 = WEST;
			break;
/*
  __   __
	\ /
*/
		case VCurve:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(2);
			ways[0].s1 = SOUTH;
			ways[0].s2 = EAST;
			ways[1].s1 = SOUTH;
			ways[1].s2 = WEST;
			break;
/*
  __ |
	\|
*/
		case StraightLCurve:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(2);
			ways[0].s1 = NORTH;
			ways[0].s2 = SOUTH;
			ways[1].s1 = WEST;
			ways[1].s2 = SOUTH;
			break;
/*
  |  __
  |/
*/
		case StraightRCurve:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(2);
			ways[0].s1 = NORTH;
			ways[0].s2 = SOUTH;
			ways[1].s1 = EAST;
			ways[1].s2 = SOUTH;
			break;
/*
  _______
	\ /
	 V
*/
		case HStraightVCurve:
			tree = true;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(3);
			ways[0].s1 = WEST;
			ways[0].s2 = EAST;
			ways[1].s1 = WEST;
			ways[1].s2 = SOUTH;
			ways[2].s1 = EAST;
			ways[2].s2 = SOUTH;
			break;
/*
   __ | __
	 \|/
	  V
*/
		case VStraightVCurve:
			tree = true;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(4);
			ways[0].s1 = WEST;
			ways[0].s2 = EAST;
			ways[1].s1 = WEST;
			ways[1].s2 = SOUTH;
			ways[2].s1 = EAST;
			ways[2].s2 = SOUTH;
			ways[3].s1 = NORTH;
			ways[3].s2 = SOUTH;
			break;
/*
  __/ \__
	\ /
*/
		case CrossCurves:
			tree = true;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(4);
			ways[0].s1 = NORTH;
			ways[0].s2 = EAST;
			ways[1].s1 = NORTH;
			ways[1].s2 = WEST;
			ways[2].s1 = SOUTH;
			ways[2].s2 = WEST;
			ways[3].s1 = SOUTH;
			ways[3].s2 = EAST;
			break;
/*
	 |\__
  __ |
	\|
*/
		case StraightLDoubleCurves:
			tree = true;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(3);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			ways[1].s1 = EAST;
			ways[1].s2 = NORTH;
			ways[2].s1 = NORTH;
			ways[2].s2 = SOUTH;
			break;
/*
  __/|
	 | __
	 |/
*/
		case StraightRDoubleCurves:
			tree = true;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(3);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			ways[1].s1 = WEST;
			ways[1].s2 = NORTH;
			ways[2].s1 = NORTH;
			ways[2].s2 = SOUTH;
			break;
		case Empty:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Wall:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus1_1:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = NORTH;
			break;
		case Terminus1_2:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus2_1:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = NORTH;
			break;
		case Terminus2_2:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus3_1:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = NORTH;
			break;
		case Terminus3_2:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus4_1:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus4_2:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus5_1:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus5_2:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus6_1:
			tree = false;
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus6_2:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus2_3:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus2_4:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = NORTH;
			break;
		case Terminus1_3:
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus1_4:
			tree = false;
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = NORTH;
			break;
		case Terminus3_3:
			tree = false;
			tree = false;
			access[NORTH] = IMPOSSIBLE;
			access[SOUTH] = OBLIGATORY;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = SOUTH;
			break;
		case Terminus3_4:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = NORTH;
			break;
		case Terminus5_3:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = NORTH;
			break;
		case Terminus5_4:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = NORTH;
			break;
		case Terminus4_3:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = NORTH;
			break;
		case Terminus4_4:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = NORTH;
			break;
		case Terminus6_3:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = IMPOSSIBLE;
			access[WEST] = OBLIGATORY;
			ways.resize(1);
			ways[0].s1 = WEST;
			ways[0].s2 = NORTH;
			break;
		case Terminus6_4:
			tree = false;
			access[NORTH] = OBLIGATORY;
			access[SOUTH] = IMPOSSIBLE;
			access[EAST] = OBLIGATORY;
			access[WEST] = IMPOSSIBLE;
			ways.resize(1);
			ways[0].s1 = EAST;
			ways[0].s2 = NORTH;
			break;
		default:
			cout << "ERROR: Constructor Tile: Bad idTile " << getType();
			break;
	}
}

int Tile::getTurn()
{
	return turn;
}
