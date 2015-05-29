#include "YourIdPlayer.h"

using namespace std;

YourIdPlayer::YourIdPlayer() : Pack(YOURIDPLAYER){}

YourIdPlayer::YourIdPlayer(int idP) : Pack(YOURIDPLAYER){
    idPlayer = idP;
}

void YourIdPlayer::print(ostream &f){
    Pack::print(f);
    f << idPlayer;
}

void YourIdPlayer::read(istream &f){
    
    f >> idPlayer;
}
