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
where board(i) and board(j) represents the number of elements in the i/j line.
 */
typedef std::vector<int> board;

enum mode { PvP, PvC, CvC };

enum difficulty { Easy, Medium, Hard }; 
#endif
