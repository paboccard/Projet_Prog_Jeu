#ifndef PLAYERSERVER_H
#define PLAYERSERVER_H

#include "../Shared/Player.h"


class PlayerServer : public Player
{
    public:
        ProdCons *circularQueue;

        PlayerServer();
        ~PlayerServer();
    private:

};

#endif // PLAYERSERVER_H
