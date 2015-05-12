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
    emit(hoverEnter(x, y));
}

void GaufreItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    emit(hoverLeave(x, y));
}

void GaufreItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        emit(pressed(x, y));
    }
}

void GaufreItem::setImage(QPixmap *pixmap) {
    setPixmap(*pixmap);
}
