#ifndef CARD_H
#define CARD_H
#include <vector>
#include "Utils.h"
#include <fstream>

class Card {
 public:
    int numCard;
    Card(int card = 0);

    int* whichStation(int line);

    friend std::ostream& operator << (std::ostream &f, Card &c);
    friend std::istream& operator >> (std::istream &f, Card &c);

 private:
    int card[6][3];
    void add(int line, idTile station1, idTile station2, idTile station3);
};


#endif
