#ifndef CIRCULARQUEUECLIENT_H
#define CIRCULARQUEUECLIENT_H

#include "../Shared/Pack.h"
#include "../Shared/ProdCons.h"
#include <iostream>
#include <fstream>


class CircularQueueClient : public Pack{

 public:
    ProdCons<Pack*> *prodConsClient;

    CircularQueueClient();
    CircularQueueClient(ProdCons<Pack*> *prod);

    void print(std::ostream& f);
    void read(std::istream& f);

};

#endif
