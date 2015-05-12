#include "GaufreItem.h"
#include <iostream>

using namespace std;

GaufreItem::GaufreItem(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent)
{
    p.x = 0;
    p.y = 0;
    setAcceptHoverEvents(true);
}

GaufreItem::GaufreItem(Point p) :
    QGraphicsPixmapItem()
{
    this->p = p;
    setAcceptHoverEvents(true);
}

GaufreItem::~GaufreItem()
{
    cout << "kill" << endl;
}

void GaufreItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    emit(hoverEnter(p));
}

void GaufreItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    emit(hoverLeave(p));
}

void GaufreItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        emit(pressed(p));
    }
}

void GaufreItem::setImage(QPixmap *pixmap) {
    setPixmap(*pixmap);
}
