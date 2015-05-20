#include <Won.h>
#include <fstream>

Won::Won(int idP){
    idPlayer = idP;
}

Won::writePack(int fd){
    stringstream ss;
    ss << idPlayer;

    ss.seekg(0, ios::end);
    int size = ss.tellg(); //size contain the size (in bytes) of the string

    write(fd, ss.str().c_str(), size);
}
