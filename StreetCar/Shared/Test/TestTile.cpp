#include <iostream>
#include "../Tile.h"

using namespace std;

int main()
{
	Tile t = Tile(HStraightVCurve, 0, 4, 4);
	Square s = t;
	
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
	cout << s << endl;
	
	cout << "----- Rotation 180° -----" << endl;
	t.rotate();
	t.rotate();
	s = t;
	cout << t << endl;
	cout << s << endl;
	
	
	return 0;
}