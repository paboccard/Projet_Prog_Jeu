#include "../Computer.h"

int main() {

	cout << "Test: >>>>> >>>>> >>>>> TestComputer <<<<< <<<<< <<<<< <<<<<" << endl << endl;
	
	vector<Tile> hand;
	PlayTile p ;
	ElementPath elt ;
	
	
	cout << "Test: >>>>> >>>>> >>>>> Creation main: en cours <<<<< <<<<< <<<<< <<<<<" << endl ;
	Tile t1 = Tile(Curve, -1, -1, 0);
	Tile t2 = Tile(Straight, -1, -1, 0);
	Tile t3 = Tile(Straight, -1, -1, 0);
	Tile t4 = Tile(Straight, -1, -1, 0);
	Tile t5 = Tile(Straight, -1, -1, 0);
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
	std::vector<vector<Tile> > h;
	h.resize(0);
	h.push_back(hand);
	Computer c = Computer(h, 0, g);
	
	elt.p = {1,3};
	elt.prec = NORTH;
	elt.suiv = SOUTH;
	c.setElementPath(elt);
	
	elt.p = {2,3};
	elt.prec = NORTH;
	elt.suiv = EAST;
	c.setElementPath(elt);
	
	elt.p = {2,4};
	elt.prec = WEST;
	elt.suiv = EAST;
	c.setElementPath(elt);
	
	elt.p = {2,5};
	elt.prec = WEST;
	elt.suiv = EAST;
	c.setElementPath(elt);
	
	elt.p = {2,6};
	elt.prec = WEST;
	elt.suiv = NORTH;
	c.setElementPath(elt);
	
	elt.p = {1,6};
	elt.prec = SOUTH;
	elt.suiv = NORTH;
	c.setElementPath(elt);
	cout << "Test: >>>>> >>>>> >>>>> Creation Computer: termine <<<<< <<<<< <<<<< <<<<<" << endl ;
	
	c.getMyPlayer().printHand();
	
	int t = 0;
	bool impossible = false;
	int z ;
	for(z = 0 ; z < 5 && !impossible; z++){
		
		cout << "Test: >>>>> >>>>> >>>>> Calcul du coup: en cours <<<<< <<<<< <<<<< <<<<<" << endl ;
		p = c.medium();
		cout << "Test: >>>>> >>>>> >>>>> Calcul du coup: termine <<<<< <<<<< <<<<< <<<<<" << endl ;
		
		cout << "Test: >>>>> >>>>> >>>>> Coup joué: debut <<<<< <<<<< <<<<< <<<<<" << endl ;
// 		cout << p << endl;
		cout << "Test: >>>>> >>>>> >>>>> Coup joué: termine <<<<< <<<<< <<<<< <<<<<" << endl ;

// 		/*On pose la tuile si elle existe*/ 
		if(!c.isBlock()){
			cout << "Test: >>>>> >>>>> >>>>> Pose tuile: debut <<<<< <<<<< <<<<< <<<<<" << endl ;
			t = t + 2;
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
	cout << "Tuiles posees: " << t << endl;
	
	
	return 0;
}