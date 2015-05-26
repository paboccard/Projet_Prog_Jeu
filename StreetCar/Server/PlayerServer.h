#ifndef PLAYERSERVER_H
#define PLAYERSERVER_H

#include "../Shared/Player.h"
#include "../Shared/Packs.h"
#include "../Shared/Pack.h"
#include "../Shared/ProdCons.h"
#include "../Shared/Board.h"


class PlayerServer : public Player
{
 public:
    ProdCons<Pack*> *circularQueue;
    
    PlayerServer();
    ~PlayerServer();

};

#endif // PLAYERSERVER_H
