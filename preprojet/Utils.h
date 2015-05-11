#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <vector>

/*

| | | | |
| | | |0|

0 is the point(1,3), x=1 and y=3.

*/
typedef struct{
    int x;
    int y;
} Point;

/*
forall i,j and i<j, board(j)<=board(i)
 */
typedef std::vector<int> board;

#endif
