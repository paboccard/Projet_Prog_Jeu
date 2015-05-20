#include <PlayedTile.h>
#include <fstream>

using namespace std;

PlayedTile::PlayedTile(int idP, Stroke s[2]){
    idNextPlayer = idP;
    strokePlayed = s;
}

PlayedTile::writePack(int fd){
    stringstream ss;
    ss << idNextPlayer;

    for (int i = 0; i<2<i++)
	ss << " " << t[i];

    ss.seekg(0, ios::end);
    int size = ss.tellg(); //size contain the size (in bytes) of the string

    write(fd, ss.str().c_str(), size);
}
