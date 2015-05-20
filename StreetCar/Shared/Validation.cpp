#include "Validation.h"
#include <fstream>

Validation::Validation(int error){
    errorNbr = error;
}

Validation::writePack(int fd){
    stringstream ss;
    ss << errorNbr;

    ss.seekg(0, ios::end);
    int size = ss.tellg(); //size contain the size (in bytes) of the string

    write(fd, ss.str().c_str(), size);
}
