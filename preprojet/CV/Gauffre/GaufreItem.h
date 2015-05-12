#ifndef GAUFREITEM_H
#define GAUFREITEM_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QObject>
#include "../../Utils.h"

class GaufreItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    GaufreItem(QGraphicsItem * parent = 0);
    GaufreItem(Point p);
    ~GaufreItem();

    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setImage(QPixmap *pixmap);

signals:
    void hoverEnter(Point);
    void hoverLeave(Point);
    void pressed(Point);

private:
    Point p;

};

#endif // GAUFREITEM_H
