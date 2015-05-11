#include "ImageGaufre.h"

ImageGaufre::ImageGaufre(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent)
{
    x = 0;
    y = 0;
    QPixmap pixmap("../Gauffre/gaufre.png");
    setPixmap(pixmap);
}

ImageGaufre::ImageGaufre(int x, int y) :
    QGraphicsPixmapItem()
{
    this->x = x;
    this->y = y;

}
