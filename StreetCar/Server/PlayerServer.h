#ifndef PLAYERSERVER_H
#define PLAYERSERVER_H

#include "../Shared/Player.h"
#include "../Shared/Packs.h"


class PlayerServer : public Player
{
    public:
        ProdCons *circularQueue<Pack>;

        PlayerServer();
        ~PlayerServer();
    private:

};

#endif // PLAYERSERVER_H
