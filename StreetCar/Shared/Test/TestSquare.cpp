#include<iostream>
#include "../Square.h"

void printStatus(Square s){
	cout << s ;
	cout << "is Empty ? " << s.isEmpty() << endl ;
	cout << "is Terminus ? " << s.isTerminus() << endl;
	cout << "is Station ? " << s.isStation() << endl;
	cout << "is Wall ? " << s.isWall() << endl << endl;
}

int main()
{
	cout << "Test of Square.cpp" << endl << endl;
	
	cout << "Straight" << endl;
	Square s = Square(Straight, 0, 0);
	printStatus(s);
		
	cout << "Curve" << endl;
	s = Square(Curve, 1, 1);
	printStatus(s);
	
	cout << "DoubleCurves" << endl;
	s = Square(Curve, 2, 2);
	printStatus(s);
	
	cout << "Intersect" << endl;
	s = Square(Intersect, 3, 3);
	printStatus(s);
	
	cout << "VCurve" << endl;
	s = Square(VCurve, 4, 1);
	printStatus(s);
	
	cout << "StraightLCurve" << endl;
	s = Square(StraightLCurve, 5, 1);
	printStatus(s);
	
	cout << "StraightRCurve" << endl;
	s = Square(StraightRCurve, 6, 1);
	printStatus(s);
	
	cout << "HStraightVCurve" << endl;
	s = Square(HStraightVCurve, 7, 1);
	printStatus(s);
	
	cout << "VStraightVCurve" << endl;
	s = Square(VStraightVCurve, 8, 1);
	printStatus(s);
	
	cout << "CrossCurves" << endl;
	s = Square(CrossCurves, 9, 1);
	printStatus(s);
	
	cout << "StraightLDoubleCurves" << endl;
	s = Square(StraightLDoubleCurves, 10, 1);
	printStatus(s);
	
	cout << "StraightRDoubleCurves" << endl;
	s = Square(StraightRDoubleCurves, 11, 1);
	printStatus(s);
	
	cout << "StationA" << endl;
	s = Square(StationA, 12, 1);
	printStatus(s);
	
	cout << "StationB" << endl;
	s = Square(StationB, 13, 1);
	printStatus(s);
	
	cout << "StationC" << endl;
	s = Square(StationC, 14, 1);
	printStatus(s);
	
	cout << "StationD" << endl;
	s = Square(StationD, 15, 1);
	printStatus(s);
	
	cout << "StationE" << endl;
	s = Square(StationE, 16, 1);
	printStatus(s);
	
	cout << "StationF" << endl;
	s = Square(StationF, 17, 1);
	printStatus(s);
	
	cout << "StationG" << endl;
	s = Square(StationG, 18, 1);
	printStatus(s);
	
	cout << "StationH" << endl;
	s = Square(StationH, 19, 1);
	printStatus(s);
	
	cout << "StationI" << endl;
	s = Square(StationI, 20, 1);
	printStatus(s);
	
	cout << "StationJ" << endl;
	s = Square(StationJ, 21, 1);
	printStatus(s);
	
	cout << "StationK" << endl;
	s = Square(StationK, 22, 1);
	printStatus(s);
	
	cout << "StationL" << endl;
	s = Square(StationL, 23, 1);
	printStatus(s);
	
	cout << "Wall" << endl;
	s = Square(Wall, 24, 1);
	printStatus(s);
	
	cout << "Terminus1_1" << endl;
	s = Square(Terminus1_1, 25, 1);
	printStatus(s);
	
	cout << "Terminus1_2" << endl;
	s = Square(Terminus1_2, 26, 1);
	printStatus(s);
	
	cout << "Terminus1_3" << endl;
	s = Square(Terminus1_3, 27, 1);
	printStatus(s);
	
	cout << "Terminus1_4" << endl;
	s = Square(Terminus1_4, 28, 1);
	printStatus(s);
	
	cout << "Terminus2_1" << endl;
	s = Square(Terminus2_1, 29, 1);
	printStatus(s);
	
	cout << "Terminus2_2" << endl;
	s = Square(Terminus2_2, 30, 1);
	printStatus(s);
	
	cout << "Terminus2_3" << endl;
	s = Square(Terminus2_3, 31, 1);
	printStatus(s);
	
	cout << "Terminus2_4" << endl;
	s = Square(Terminus2_4, 32, 1);
	printStatus(s);
	
	cout << "Terminus3_1" << endl;
	s = Square(Terminus3_1, 33, 1);
	printStatus(s);
	
	cout << "Terminus3_2" << endl;
	s = Square(Terminus3_2, 34, 1);
	printStatus(s);
	
	cout << "Terminus3_3" << endl;
	s = Square(Terminus3_3, 35, 1);
	printStatus(s);
	
	cout << "Terminus3_4" << endl;
	s = Square(Terminus3_4, 36, 1);
	printStatus(s);
	
	cout << "Terminus4_1" << endl;
	s = Square(Terminus4_1, 37, 1);
	printStatus(s);
	
	cout << "Terminus4_2" << endl;
	s = Square(Terminus4_2, 38, 1);
	printStatus(s);
	
	cout << "Terminus4_3" << endl;
	s = Square(Terminus4_3, 39, 1);
	printStatus(s);
	
	cout << "Terminus4_4" << endl;
	s = Square(Terminus4_4, 40, 1);
	printStatus(s);
	
	cout << "Terminus5_1" << endl;
	s = Square(Terminus5_1, 41, 1);
	printStatus(s);
	
	cout << "Terminus5_2" << endl;
	s = Square(Terminus5_2, 42, 1);
	printStatus(s);
	
	cout << "Terminus5_3" << endl;
	s = Square(Terminus5_3, 43, 1);
	printStatus(s);
	
	cout << "Terminus5_4" << endl;
	s = Square(Terminus5_4, 44, 1);
	printStatus(s);
	
	cout << "Terminus6_1" << endl;
	s = Square(Terminus6_1, 45, 1);
	printStatus(s);
	
	cout << "Terminus6_2" << endl;
	s = Square(Terminus6_2, 46, 1);
	printStatus(s);
	
	cout << "Terminus6_3" << endl;
	s = Square(Terminus6_3, 47, 1);
	printStatus(s);
	
	cout << "Terminus6_4" << endl;
	s = Square(Terminus6_4, 48, 1);
	printStatus(s);
	
	cout << "Empty" << endl;
	s = Square(Empty, 49, 1);
	printStatus(s);
	
	cout << "EmptyHand" << endl;
	s = Square(EmptyHand, 50, 1);
	printStatus(s);

	
	return 0;
}