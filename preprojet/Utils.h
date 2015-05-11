#ifndef UTILS_H
#define UTILS_H
#include <iostream>

typedef struct{
    int x;
    int y;
} Point;

enum Case {Poison, Eatable, Eaten};

typedef vector<vector<Case>> Board;

#endif
