#include "../Computer.h"

int main() {

	cout << ">>>>>> TestComputer <<<<<<" << endl << endl;
	
	vector<Tile*> hand;
	
	cout << ">>>>>> Creation main: en cours <<<<<<" << endl ;
	Tile* t1 = new Tile(Curve, -1, -1, 0);
	Tile* t2 = new Tile(DoubleCurves, -1, -1, 0);
	Tile* t3 = new Tile(Straight, -1, -1, 0);
	Tile* t4 = new Tile(Intersect, -1, -1, 0);
	Tile* t5 = new Tile(HStraightVCurve, -1, -1, 0);
	hand.push_back(t1);
	hand.push_back(t2);
	hand.push_back(t3);
	hand.push_back(t4);
	hand.push_back(t5);
	cout << ">>>>>> Creation main: termine <<<<<<" << endl ;
	
	cout << ">>>>>> Creation GoalPlayer: en cours <<<<<<" << endl ;
	GoalPlayer g;
	g.line = 1;
	g.stop = Card();
	cout << ">>>>>> Creation GoalPlayer: termine <<<<<<" << endl ;
	
	cout << ">>>>>> Creation Computer: en cours <<<<<<" << endl ;
	std::vector<vector<Tile*> > h;
	h.resize(0);
	h.push_back(hand);
	Computer c = Computer(h, 0, g);
	cout << ">>>>>> Creation Computer: termine <<<<<<" << endl ;
	
	bool block = false;
	int z = 0;
// 	for(z = 0 ; z < 200 && !block; z++){
		
		cout << ">>>>> >>>>> >>>>> >>>>> Calcul du coup: en cours <<<<< <<<<< <<<<< <<<<<" << endl ;
		PlayTile p = c.easy();
		cout << ">>>>> >>>>> >>>>> >>>>> Calcul du coup: termine <<<<< <<<<< <<<<< <<<<<" << endl ;
		
		cout << ">>>>> >>>>> >>>>> >>>>> Coup joué: debut <<<<< <<<<< <<<<< <<<<<" << endl ;
		cout << p << endl;
		cout << ">>>>> >>>>> >>>>> >>>>> Coup joué: termine <<<<< <<<<< <<<<< <<<<<" << endl ;

		/*On pose la tuile si elle existe*/ 
		if(p.idxHand[0] != -1 && p.idxHand[1] != -1){
			cout << ">>>>> >>>>> >>>>> >>>>> Pose tuile: debut <<<<< <<<<< <<<<< <<<<<" << endl ;
			c.getBoard()->put(p.tiles[0]);
 			c.getBoard()->put(p.tiles[1]);
			cout << ">>>>> >>>>> >>>>> >>>>> Pose tuile: termine <<<<< <<<<< <<<<< <<<<<" << endl ;
		}
		else{
			block = true;
		}
// 	}
	
	cout << "block: " << block << " z: " << z << endl;
	c.getBoard()->printConsole();
	
	
	return 0;
}