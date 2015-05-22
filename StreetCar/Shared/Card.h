#ifndef CARD_H
#define CARD_H

class Card {
private:
    int card[6][3];
public:
    Card();
	Card(int line, int station1, int station2, int station3);
};

#endif