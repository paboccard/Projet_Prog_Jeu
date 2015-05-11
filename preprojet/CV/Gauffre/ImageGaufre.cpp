#include "ImageGaufre.h"
#include <iostream>

using namespace std;

ImageGaufre::ImageGaufre(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent)
{
    x = 0;
    y = 0;
    setAcceptHoverEvents(true);
}

ImageGaufre::ImageGaufre(int x, int y) :
    QGraphicsPixmapItem()
{
    this->x = x;
    this->y = y;
    setAcceptHoverEvents(true);
}

void ImageGaufre::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    cout << "enter" << endl;
    setPixmap(QPixmap("../Gauffre/gaufreSelect.png"));
    emit(hoverEnter(x, y));
}

void ImageGaufre::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    cout << "leave" << endl;
    setPixmap(QPixmap("../Gauffre/gaufre.png"));
    emit(hoverEnter(x, y));
}

void ImageGaufre::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton)
        cout << "press" << endl;
}

void ImageGaufre::setImage(QPixmap *pixmap) {
    setPixmap(*pixmap);
}
