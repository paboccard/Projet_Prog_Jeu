#include "GaufreItem.h"
#include <iostream>

using namespace std;

GaufreItem::GaufreItem(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent)
{
    x = 0;
    y = 0;
    setAcceptHoverEvents(true);
}

GaufreItem::GaufreItem(int x, int y) :
    QGraphicsPixmapItem()
{
    this->x = x;
    this->y = y;
    setAcceptHoverEvents(true);
}

void GaufreItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    cout << "enter" << endl;
    emit(hoverEnter(x, y));
}

void GaufreItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    cout << "leave" << endl;
    emit(hoverLeave(x, y));
}

void GaufreItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton)
        cout << "press" << endl;
}

void GaufreItem::setImage(QPixmap *pixmap) {
    setPixmap(*pixmap);
}
