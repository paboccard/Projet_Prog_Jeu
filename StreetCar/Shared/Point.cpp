#include "Point.h"

using namespace std;

bool operator != (Point p1, Point p2){
    return (p1.x != p2.x) || (p1.y != p2.y); 
}

bool operator == (Point &p1, Point &p2){
    return (p1.x == p2.x) && (p1.y == p2.y); 
}

ostream& operator << (std::ostream &f, Point &s){
	f << s.x << " " << s.y;
	return f;
}

istream& operator >> (istream &f, Point &s){
    f >> s.x;
    f >> s.y;
    return f;
}
