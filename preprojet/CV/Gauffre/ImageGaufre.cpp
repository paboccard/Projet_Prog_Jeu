#include "ImageGaufre.h"

ImageGaufre::ImageGaufre(int x, int y) :
    QGraphicsPixmapItem()
{
    this->x = x;
    this->y = y;
    QPixmap pixmap("../Gauffre/gaufre.png");
    setPixmap(pixmap);
}
