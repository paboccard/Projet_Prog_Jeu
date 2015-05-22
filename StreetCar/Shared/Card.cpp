#include "Card.h"


Card::Card() {}

Card::Card(int line, int station1, int station2, int station3){
	card[line][0] = station1;
	card[line][1] = station2;
	card[line][2] = station3;
}
