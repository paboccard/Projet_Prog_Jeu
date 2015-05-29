#ifndef POINT_H
#define POINT_H


struct Point{
    int x;
    int y;
    
    Point operator = (Point p){
	x = p.x;
	y = p.y;
	return p;
    }
};


typedef struct Point Point;

bool operator != (Point &p1, Point &p2);
bool operator == (Point &p1, Point &p2);


#endif
