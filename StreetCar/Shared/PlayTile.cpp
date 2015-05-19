#include <PlayTile.h>
#include <fstream>

using namespace std;

PlayTile::PlayTile(int idP, Stroke s[2]){
    idPlayer = idP;
    strokePlayed = s;
}

PlayTile::writePack(int fd){
    stringstream ss;
    ss << idPlayer;

    for (int i = 0; i<2<i++)
	ss << " " << t[i];

    ss.seekg(0, ios::end);
    int size = ss.tellg(); //size contain the size (in bytes) of the string

    write(fd, ss.str().c_str(), size);
}
