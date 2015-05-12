#ifndef GAUFREITEM_H
#define GAUFREITEM_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QObject>

class GaufreItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    GaufreItem(QGraphicsItem * parent = 0);
    GaufreItem(int x, int y);

    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setImage(QPixmap *pixmap);

signals:
    void hoverEnter(int, int);
    void hoverLeave(int, int);
    void pressed(int, int);

private:
    int x;
    int y;

};

#endif // GAUFREITEM_H
