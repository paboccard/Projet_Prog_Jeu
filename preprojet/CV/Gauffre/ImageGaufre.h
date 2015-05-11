#ifndef IMAGEGAUFRE_H
#define IMAGEGAUFRE_H

#include <QGraphicsItem>

class ImageGaufre : public QGraphicsPixmapItem
{

public:
    ImageGaufre(QGraphicsItem * parent = 0);
    ImageGaufre(int x, int y);

    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    int x;
    int y;

};

#endif // IMAGEGAUFRE_H
