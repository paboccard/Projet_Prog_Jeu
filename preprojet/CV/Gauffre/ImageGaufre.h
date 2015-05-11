#ifndef IMAGEGAUFRE_H
#define IMAGEGAUFRE_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QObject>

class ImageGaufre : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    ImageGaufre(QGraphicsItem * parent = 0);
    ImageGaufre(int x, int y);

    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void hoverEnter(int x, int y);
    void hoverLeave(int x, int y);

private:
    int x;
    int y;

};

#endif // IMAGEGAUFRE_H
