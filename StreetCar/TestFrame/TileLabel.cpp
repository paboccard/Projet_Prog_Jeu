#include "TileLabel.h"
#include <QDebug>

TileLabel::TileLabel(QWidget *parent, idTile i, int x, int y) :
	QLabel(parent), Tile(i, x, y)
{
	//setMinimumSize(TILESIZE-1, TILESIZE-1);
	//setPixmap(getPixmap(i));

	setAttribute(Qt::WA_DeleteOnClose);
	canMove = false;
	updatePixmap();
}

TileLabel::~TileLabel()
{

}

void TileLabel::updatePixmap() {
	QTransform t;
	t.rotate(90*getTurn());
	setPixmap(getPixmap(getType()).scaled(width(), height(), Qt::KeepAspectRatioByExpanding).transformed(t));}

int TileLabel::heightForWidth(int i)
{
	qDebug() << "height for with " << i;
	return i;
}

void TileLabel::setEmpty()
{
	Tile::setType(Empty);
	updatePixmap();
}

void TileLabel::resizeEvent(QResizeEvent *e)
{
	qDebug() << "label resize tile " << e->size();
	int min;
	if (e->size().width() < e->size().height())
		min = e->size().width();
	else
		min = e->size().height();
	setMaximumSize(min, min);
	setMinimumSize(min, min);

	updatePixmap();
}

QDataStream &operator>>(QDataStream &f, TileLabel &c)
{
	int ty;
	f >> ty;
	c.setType((idTile)ty);

	Rail r;
	f >> c.tree;

	int nbrT;
	f >> nbrT;
	c.ways.clear();
	for (int i = 0; i<nbrT; i++){
		int s1, s2;
		f >> s1;
		f >> s2;
		r.s1 = (Orientation)s1;
		r.s2 = (Orientation)s2;
		c.ways.push_back(r);
	}

	f >> c.turn;

	f >> c.idPlayer;
	for (int i = 0; i<4; i++){
		f >> c.access[i];
	}
	return f;
}


