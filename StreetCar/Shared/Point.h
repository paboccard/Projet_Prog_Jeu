#ifndef POINT_H
#define POINT_H


struct Point{
    int x;
    int y;
};


typedef struct Point Point;

void operator != (Point &p1, Point &p2);
bool operator != (Point &p1, Point &p2);
bool operator == (Point &p1, Point &p2);


#endif
