#ifndef IMAGEGAUFRE_H
#define IMAGEGAUFRE_H

#include <QGraphicsItem>

class ImageGaufre : public QGraphicsPixmapItem
{

public:
    ImageGaufre(QGraphicsItem * parent = 0);
    ImageGaufre(int x, int y);

private:
    int x;
    int y;

};

#endif // IMAGEGAUFRE_H
