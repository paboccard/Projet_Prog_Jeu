#ifndef CARD_H
#define CARD_H
#include <vector>
#include "Utils.h"
class Card {
public:
    idTile card[6][3];
    std::vector<idTile> Card::whichStation(int line);
    Card(int card);
private:
    add(int line, int station1, int station2, int station3);
};

#endif
