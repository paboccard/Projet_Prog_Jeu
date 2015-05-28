#include "YourIdPlayer.h"

using namespace std;

YourIdPlayer::YourIdPlayer() : Pack(YOURIDPLAYER){}

YourIdPlayer::YourIdPlayer(int nbrP) : Pack(YOURIDPLAYER){
    nbrPlayer = nbrP;
}

void YourIdPlayer::print(ostream &f){
    Pack::print(f);
    f << nbrPlayer;
}

void YourIdPlayer::read(istream &f){
    
    f >> nbrPlayer;
}
