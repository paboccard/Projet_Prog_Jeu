#include "../Computer.h"

int main() {

	cout << ">>>>>> TestComputer <<<<<<" << endl << endl;
	
	vector<Tile> hand;
	
	cout << ">>>>>> Creation main: en cours <<<<<<" << endl ;
	Tile* t1 = new Tile(Curve, -1, -1, 0);
	Tile* t2 = new Tile(DoubleCurves, -1, -1, 0);
	Tile* t3 = new Tile(Straight, -1, -1, 0);
	Tile* t4 = new Tile(Intersect, -1, -1, 0);
	Tile* t5 = new Tile(HStraightVCurve, -1, -1, 0);
	hand.push_back(*t1);
	hand.push_back(*t2);
	hand.push_back(*t3);
	hand.push_back(*t4);
	hand.push_back(*t5);
	cout << ">>>>>> Creation main: termine <<<<<<" << endl ;
	
	cout << ">>>>>> Creation GoalPlayer: en cours <<<<<<" << endl ;
	GoalPlayer g;
	g.line = 1;
	g.stop = Card();
	cout << ">>>>>> Creation GoalPlayer: termine <<<<<<" << endl ;
	
	cout << ">>>>>> Creation Computer: en cours <<<<<<" << endl ;
	std::vector<vector<Tile> > h;
	h.resize(0);
	h.push_back(hand);
	Computer c = Computer(h, 0, g);
	cout << ">>>>>> Creation Computer: termine <<<<<<" << endl ;
	
	c.getMyPlayer().printHand();
	
	cout << ">>>>>> Calcul du coup: en cours <<<<<<" << endl ;
	//PlayTile p = c.easy();
	cout << ">>>>>> Calcul du coup: termine <<<<<<" << endl ;
	
	
	return 0;
}