#include <iostream>
#include "../Player.h"
#include "../Tile.h"

int main()
{
	cout << "Test of Player.cpp" << endl << endl;
	Player p = Player();
	int tab[320][4];

	p.hand[0] = Tile(Straight, 0);
	p.hand[1] = Tile(Curve, 0);
	p.hand[2] = Tile(DoubleCurves, 0);
	p.hand[3] = Tile(HStraightVCurve, 0);
	p.hand[4] = Tile(StraightLCurve, 0);
	
	/*La fonction a change 
	  Le test n'est plus correct
	 
	 */
// 	p.strokePossible(tab);
// 	
// 	for(int i = 0; i< 320 ; i++){
// 		cout << tab[i][0] << " " << tab[i][1] << "  ||  " << tab[i][2] << " " << tab[i][3] << endl;
// 	}
	
	return 0;
}