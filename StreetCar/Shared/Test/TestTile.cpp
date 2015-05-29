#include <iostream>
#include "../Tile.h"

using namespace std;

int main()
{
	Tile t = Tile(HStraightVCurve, 0);
	Square s = Tile(HStraightVCurve, 0);
	
// 	cout << t ;
// 	
// 	t.rotate();
// 	
// 	cout << t ;
// 	
// 	t.rotate();
// 	
// 	cout << t ;
// 	
// 	t.rotate();
	
	cout << t << endl;
	cout << s ;
	
	return 0;
}