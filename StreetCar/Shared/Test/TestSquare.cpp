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
	Square s = Square(0, 0, Straight);
	printStatus(s);
		
	cout << "Curve" << endl;
	s = Square(1, 1, Curve);
	printStatus(s);
	
	cout << "DoubleCurves" << endl;
	s = Square(2, 2, DoubleCurves);
	printStatus(s);
	
	cout << "Intersect" << endl;
	s = Square(3, 3, Intersect);
	printStatus(s);
	
	cout << "VCurve" << endl;
	s = Square(4, 1, VCurve);
	printStatus(s);
	
	cout << "StraightLCurve" << endl;
	s = Square(5, 1, StraightLCurve);
	printStatus(s);
	
	cout << "StraightRCurve" << endl;
	s = Square(6, 1, StraightRCurve);
	printStatus(s);
	
	cout << "HStraightVCurve" << endl;
	s = Square(7, 1, HStraightVCurve);
	printStatus(s);
	
	cout << "VStraightVCurve" << endl;
	s = Square(8, 1, VStraightVCurve);
	printStatus(s);
	
	cout << "CrossCurves" << endl;
	s = Square(9, 1, CrossCurves);
	printStatus(s);
	
	cout << "StraightLDoubleCurves" << endl;
	s = Square(10, 1, StraightLDoubleCurves);
	printStatus(s);
	
	cout << "StraightRDoubleCurves" << endl;
	s = Square(11, 1, StraightRDoubleCurves);
	printStatus(s);
	
	cout << "StationA" << endl;
	s = Square(12, 1, StationA);
	printStatus(s);
	
	cout << "StationB" << endl;
	s = Square(13, 1, StationB);
	printStatus(s);
	
	cout << "StationC" << endl;
	s = Square(14, 1, StationC);
	printStatus(s);
	
	cout << "StationD" << endl;
	s = Square(15, 1, StationD);
	printStatus(s);
	
	cout << "StationE" << endl;
	s = Square(16, 1, StationE);
	printStatus(s);
	
	cout << "StationF" << endl;
	s = Square(17, 1, StationF);
	printStatus(s);
	
	cout << "StationG" << endl;
	s = Square(18, 1, StationG);
	printStatus(s);
	
	cout << "StationH" << endl;
	s = Square(19, 1, StationH);
	printStatus(s);
	
	cout << "StationI" << endl;
	s = Square(20, 1, StationI);
	printStatus(s);
	
	cout << "StationJ" << endl;
	s = Square(21, 1, StationJ);
	printStatus(s);
	
	cout << "StationK" << endl;
	s = Square(22, 1, StationK);
	printStatus(s);
	
	cout << "StationL" << endl;
	s = Square(23, 1, StationL);
	printStatus(s);
	
	cout << "Wall" << endl;
	s = Square(24, 1, Wall);
	printStatus(s);
	
	cout << "Terminus1_1" << endl;
	s = Square(25, 1, Terminus1_1);
	printStatus(s);
	
	cout << "Terminus1_2" << endl;
	s = Square(26, 1, Terminus1_2);
	printStatus(s);
	
	cout << "Terminus1_3" << endl;
	s = Square(27, 1, Terminus1_3);
	printStatus(s);
	
	cout << "Terminus1_4" << endl;
	s = Square(28, 1, Terminus1_4);
	printStatus(s);
	
	cout << "Terminus2_1" << endl;
	s = Square(29, 1, Terminus2_1);
	printStatus(s);
	
	cout << "Terminus2_2" << endl;
	s = Square(30, 1, Terminus2_2);
	printStatus(s);
	
	cout << "Terminus2_3" << endl;
	s = Square(31, 1, Terminus2_3);
	printStatus(s);
	
	cout << "Terminus2_4" << endl;
	s = Square(32, 1, Terminus2_4);
	printStatus(s);
	
	cout << "Terminus3_1" << endl;
	s = Square(33, 1, Terminus3_1);
	printStatus(s);
	
	cout << "Terminus3_2" << endl;
	s = Square(34, 1, Terminus3_2);
	printStatus(s);
	
	cout << "Terminus3_3" << endl;
	s = Square(35, 1, Terminus3_3);
	printStatus(s);
	
	cout << "Terminus3_4" << endl;
	s = Square(36, 1, Terminus3_4);
	printStatus(s);
	
	cout << "Terminus4_1" << endl;
	s = Square(37, 1, Terminus4_1);
	printStatus(s);
	
	cout << "Terminus4_2" << endl;
	s = Square(38, 1, Terminus4_2);
	printStatus(s);
	
	cout << "Terminus4_3" << endl;
	s = Square(39, 1, Terminus4_3);
	printStatus(s);
	
	cout << "Terminus4_4" << endl;
	s = Square(40, 1, Terminus4_4);
	printStatus(s);
	
	cout << "Terminus5_1" << endl;
	s = Square(41, 1, Terminus5_1);
	printStatus(s);
	
	cout << "Terminus5_2" << endl;
	s = Square(42, 1, Terminus5_2);
	printStatus(s);
	
	cout << "Terminus5_3" << endl;
	s = Square(43, 1, Terminus5_3);
	printStatus(s);
	
	cout << "Terminus5_4" << endl;
	s = Square(44, 1, Terminus5_4);
	printStatus(s);
	
	cout << "Terminus6_1" << endl;
	s = Square(45, 1, Terminus6_1);
	printStatus(s);
	
	cout << "Terminus6_2" << endl;
	s = Square(46, 1, Terminus6_2);
	printStatus(s);
	
	cout << "Terminus6_3" << endl;
	s = Square(47, 1, Terminus6_3);
	printStatus(s);
	
	cout << "Terminus6_4" << endl;
	s = Square(48, 1, Terminus6_4);
	printStatus(s);
	
	cout << "Empty" << endl;
	s = Square(49, 1, Empty);
	printStatus(s);
	
	cout << "EmptyHand" << endl;
	s = Square(50, 1, EmptyHand);
	printStatus(s);

	
	return 0;
}