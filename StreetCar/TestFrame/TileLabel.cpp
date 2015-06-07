#include "TileLabel.h"
#include <QDebug>
#include <QPainter>

TileLabel::TileLabel(QWidget *parent, idTile i, int x, int y) :
	QLabel(parent), Tile(i, x, y)
{
	setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
	setLineWidth(1);
	setMidLineWidth(1);
	//setMaximumSize(TILESIZE*5, TILESIZE*5);
	//setMinimumSize(TILESIZE, TILESIZE);
	//setPixmap(getPixmap(i));
//	setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

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
	clear();
	setPixmap(getPixmap(getType()).scaled(width(), height(), Qt::IgnoreAspectRatio).transformed(t));
}

void TileLabel::mouseEnter(bool ok)
{
	QPixmap pix = *pixmap();
	QPainter p;
	p.begin(&pix);
	QPen pen;
	pen.setWidth(5);
	if (ok) {
		//pen.setColor(QColor(0, 255, 0, 80));
		p.fillRect(pix.rect(), QColor(0, 255, 0, 80));
	}else {
		//pen.setColor(QColor(255, 0, 0, 80));
		p.fillRect(pix.rect(), QColor(255, 0, 0, 80));
	}
	p.setPen(pen);
	//p.drawRect(5, 5, pix.width()-10, pix.height()-10);
	p.end();
	setPixmap(pix);
}

void TileLabel::mouseLeave()
{
	updatePixmap();
}

int TileLabel::heightForWidth(int i)
{
	qDebug() << "----------------------height for with " << i;
	return i;
}

void TileLabel::setEmpty()
{
	Tile::setType(Empty);
	updatePixmap();
}

void TileLabel::resizeEvent(QResizeEvent *e)
{
	//qDebug() << "label resize tile " << e->size();
	int min;
	if (e->size().width() < e->size().height())
		min = e->size().width();
	else
		min = e->size().height();
	//setMaximumSize(min, min);
	//setMinimumSize(min, min);
	//setFixedHeight(min);
	//setFixedWidth(min);
	QLabel::resizeEvent(e);
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


