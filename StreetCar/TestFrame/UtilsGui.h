#ifndef UTILSGUI_H
#define UTILSGUI_H

#include <QPixmap>
#include "../Shared/Utils.h"

//#define HAND 0
//#define BOARD 1
#define TILESIZE 55
#define SIZEHAND 50
#define TILEMAINHAND 40

QPixmap getPixmap(idTile i, bool stop = false);

#endif // UTILSGUI_H
