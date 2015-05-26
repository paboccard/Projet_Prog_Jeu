#include <iostream>
#include "../Pile.h"

using namespace std;

int main()
{
	cout << "Test of Pile.cpp" << endl << endl;
	Pile p = Pile();
	int i = 0;
	
	cout << "New Pile" << endl << endl;
	cout << p << endl;
	
	
	while(!p.isEmpty()){
		cout << "Pioche n°" << ++i << endl;
		idTile pioche = p.take();
		
		cout << "Tile taked: " << idTile(pioche) << endl << endl;
		cout << "Pile status: "<< endl;
		cout << p << endl;;
	}
	
	
	return 0;
}