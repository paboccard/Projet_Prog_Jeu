#include "ImageGaufre.h"
#include <iostream>

using namespace std;

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
    QPixmap pixmap("../Gauffre/gaufre.png");
    setPixmap(pixmap);
}

void ImageGaufre::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    cout << "poc" << endl;
}
