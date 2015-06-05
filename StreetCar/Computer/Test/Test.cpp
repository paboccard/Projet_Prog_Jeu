#include "../Computer.h"

int main() {

	cout << "Test: >>>>> >>>>> >>>>> TestComputer <<<<< <<<<< <<<<< <<<<<" << endl << endl;
	
	vector<Tile*> hand;
	
	cout << "Test: >>>>> >>>>> >>>>> Creation main: en cours <<<<< <<<<< <<<<< <<<<<" << endl ;
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
	cout << "Test: >>>>> >>>>> >>>>> Creation main: termine <<<<< <<<<< <<<<< <<<<<" << endl ;
	
	cout << "Test: >>>>> >>>>> >>>>> Creation GoalPlayer: en cours <<<<< <<<<< <<<<< <<<<<" << endl ;
	GoalPlayer g;
	g.line = 1;
	g.stop = Card();
	cout << "Test: >>>>> >>>>> >>>>> Creation GoalPlayer: termine <<<<< <<<<< <<<<< <<<<<" << endl ;
	
	cout << "Test: >>>>> >>>>> >>>>> Creation Computer: en cours <<<<< <<<<< <<<<< <<<<<" << endl ;
	std::vector<vector<Tile*> > h;
	h.resize(0);
	h.push_back(hand);
	Computer c = Computer(h, 0, g);
	cout << "Test: >>>>> >>>>> >>>>> Creation Computer: termine <<<<< <<<<< <<<<< <<<<<" << endl ;
	
	bool impossible = false;
	int z ;
	for(z = 0 ; z < 200 && !impossible; z++){
		
		cout << "Test: >>>>> >>>>> >>>>> Calcul du coup: en cours <<<<< <<<<< <<<<< <<<<<" << endl ;
		PlayTile p = c.easy();
		cout << "Test: >>>>> >>>>> >>>>> Calcul du coup: termine <<<<< <<<<< <<<<< <<<<<" << endl ;
		
		cout << "Test: >>>>> >>>>> >>>>> Coup joué: debut <<<<< <<<<< <<<<< <<<<<" << endl ;
		cout << p << endl;
		cout << "Test: >>>>> >>>>> >>>>> Coup joué: termine <<<<< <<<<< <<<<< <<<<<" << endl ;

		/*On pose la tuile si elle existe*/ 
		if(!c.isBlock()){
			cout << "Test: >>>>> >>>>> >>>>> Pose tuile: debut <<<<< <<<<< <<<<< <<<<<" << endl ;
			c.getBoard()->putComputer(p.tiles[0]);
 			c.getBoard()->putComputer(p.tiles[1]);
			cout << "Test: >>>>> >>>>> >>>>> Pose tuile: termine <<<<< <<<<< <<<<< <<<<<" << endl ;
		}
		else{
			impossible = true;
		}
	}
	
	cout << "impossible: " << impossible << " z: " << z << endl;
	c.getBoard()->printConsole();
	cout << endl;
	c.getMyPlayer().printHand();
			
	cout << "Test: >>>>> >>>>> >>>>> FIN DU TEST <<<<< <<<<< <<<<< <<<<<" << endl ;
			
	
	
	return 0;
}