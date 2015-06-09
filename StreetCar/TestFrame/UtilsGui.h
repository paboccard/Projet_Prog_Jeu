#ifndef UTILSGUI_H
#define UTILSGUI_H

#include <QPixmap>
#include "../Shared/Utils.h"

//#define HAND 0
//#define BOARD 1
#define TILESIZE 25
#define SIZEHAND 40
#define TILEMAINHAND 60

QPixmap getPixmap(idTile i, bool stop = false);

#endif // UTILSGUI_H
