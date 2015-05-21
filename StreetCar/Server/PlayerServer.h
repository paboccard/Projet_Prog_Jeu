#ifndef PLAYERSERVER_H
#define PLAYERSERVER_H

#include "../Shared/Player.h"
#include "../Shared/Packs.h"
#include "../Shared/ProdCons.h"


class PlayerServer : public Player
{
    public:
        ProdCons *circularQueue<Pack>;
        bool currentTerminus;
        Point lastTile; // to use if currentTerminus = true
        Point current;
        // orientation previous tile on board to use if currentTerminus = false
        //

        PlayerServer();
        ~PlayerServer();
    private:

};

#endif // PLAYERSERVER_H
