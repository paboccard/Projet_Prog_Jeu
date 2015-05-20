#ifndef VALIDATION_H
#define VALIDATION_H

#include <Pack.h>
#include <iostream>
#include <unistd.h>
#include <Utils.h>

class Validation : public Pack{

 public:
    int errorNbr;

    Validation(int error);
    void writePack(int fd);
};

#endif
