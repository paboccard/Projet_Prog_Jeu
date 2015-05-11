#ifndef IMAGEGAUFRE_H
#define IMAGEGAUFRE_H

#include <QGraphicsItem>

class ImageGaufre : public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit ImageGaufre(int x, int y);

signals:

public slots:

private:
    int x;
    int y;

};

#endif // IMAGEGAUFRE_H
