#include "Card.h"

using namespace std;

Card::Card(int card) {
	switch (card){
		case 0:
			add(0,StationC,StationD,StationI);
			add(1,StationB,StationD,StationM);
			add(2,StationG,StationK,StationL);
			add(3,StationE,StationF,StationK);
			add(4,StationE,StationH,StationK);
			add(5,StationA,StationL,StationM);
			break;
		case 1:
			add(0,StationF,StationH,StationK);
			add(1,StationC,StationF,StationI);
			add(2,StationG,StationM,StationL);
			add(3,StationB,StationH,StationL);
			add(4,StationD,StationI,StationM);
			add(5,StationB,StationF,StationI);
			break;
		case 2:
			add(0,StationB,StationG,StationL);
			add(1,StationB,StationL,StationM);
			add(2,StationC,StationI,StationM);
			add(3,StationA,StationD,StationM);
			add(4,StationA,StationG,StationK);
			add(5,StationB,StationF,StationM);
			break;
		case 3:
			add(0,StationF,StationI,StationK);
			add(1,StationE,StationG,StationI);
			add(2,StationD,StationH,StationK);
			add(3,StationH,StationK,StationL);
			add(4,StationA,StationE,StationL);
			add(5,StationA,StationB,StationL);
			break;
		case 4:
			add(0,StationA,StationC,StationL);
			add(1,StationC,StationG,StationK);
			add(2,StationD,StationH,StationI);
			add(3,StationC,StationE,StationM);
			add(4,StationA,StationB,StationM);
			add(5,StationE,StationI,StationK);
			break;
		case 5:
			add(0,StationC,StationG,StationM);
			add(1,StationG,StationH,StationL);
			add(2,StationC,StationD,StationM);
			add(3,StationA,StationE,StationI);
			add(4,StationD,StationF,StationI);
			add(5,StationE,StationK,StationL);
			break;

	}
}
int* Card::whichStation(int line){

	return card[line];
}

ostream& operator << (ostream &f, Card &c)
{
	for (int i = 0; i < 6 ; i ++){
		for (int j = 0; j < 3; j ++)
			f << c.card[i][j] << " ";
	}
	return f;
}

istream& operator >> (istream &f, Card &c)
{
	for (int j=0; j<6; j++){
		for (int k=0; k<3; k++){
			f >> c.card[j][k];
		}
	}
	return f;
}

void Card::add(int line, idTile station1, idTile station2, idTile station3){
	card[line][0] = station1;
	card[line][1] = station2;
	card[line][2] = station3;
}

