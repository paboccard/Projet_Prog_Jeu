#ifndef CARD_H
#define CARD_H

class Card {
public:
    int card[6][3];

    Card();
    Card(int line, int station1, int station2, int station3);
};

#endif
