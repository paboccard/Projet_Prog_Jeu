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
    setAcceptHoverEvents(true);
}

ImageGaufre::ImageGaufre(int x, int y) :
    QGraphicsPixmapItem()
{
    this->x = x;
    this->y = y;
    QPixmap pixmap("../Gauffre/gaufre.png");
    setPixmap(pixmap);
    setAcceptHoverEvents(true);
}

void ImageGaufre::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    cout << "enter" << endl;
}

void ImageGaufre::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    cout << "leave" << endl;
}

void ImageGaufre::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    cout << "press" << endl;
}
