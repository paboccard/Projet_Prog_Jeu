#include "CardWidget.h"
#include <QResizeEvent>
#include <iostream>
#include <QDebug>
#include <QPixmap>

using namespace std;

CardWidget::CardWidget(int i) : Tile()
{
	setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
	setLineWidth(1);
	setMidLineWidth(1);
	//setMaximumSize(80, 80);
	//setMinimumSize(80, 80);
	setAttribute(Qt::WA_DeleteOnClose);
	index = i;
	updatePixmap();
}

CardWidget::CardWidget(idTile t, int i) : Tile(t)
{
	setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
	setLineWidth(1);
	setMidLineWidth(1);
	//setMaximumSize(80, 80);
	//setMinimumSize(80, 80);
	setAttribute(Qt::WA_DeleteOnClose);
	index = i;
	updatePixmap();
}

void CardWidget::updatePixmap() {
	QTransform t;
	t.rotate(90*getTurn());
	setPixmap(getPixmap(getType()).scaled(width(), height(), Qt::KeepAspectRatioByExpanding).transformed(t));
}

CardWidget &CardWidget::operator =(Tile &t)
{
	Tile::operator =(t);
	return *this;
}

int CardWidget::getIndex() {
	return index;
}

void CardWidget::resizeEvent(QResizeEvent *e)
{
	int min;
	if (e->size().width() < e->size().height())
		min = e->size().width();
	else
		min = e->size().height();
	//setMaximumSize(min, min);
	//setMinimumSize(min, min);
	//setPixmap(pixmap()->scaled(e->size(), Qt::KeepAspectRatioByExpanding));
	updatePixmap();
}

void CardWidget::setEmpty()
{
	changeTile(Empty);
}

void CardWidget::changeTile(idTile t) {
	Tile::setType(t);
	updatePixmap();
}

void CardWidget::rotate()
{
	qDebug() << "rotate";
	QTransform trans;
	trans.rotate(90);
	setPixmap(pixmap()->transformed(trans));
	Tile::rotate();
}

QDataStream &operator>>(QDataStream &f, CardWidget &c)
{
	f >> c.index;
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

QDataStream &operator<<(QDataStream &f, CardWidget &c)
{
	f << c.index;
	f << (int)c.getType();
	f << (bool)c.tree <<
		(int)c.ways.size();
	for (unsigned int i = 0; i<c.ways.size(); i++){
		f << (int)c.ways[i].s1 << (int)c.ways[i].s2;
	}
	f << (int)c.turn;
	f << c.idPlayer;
	for (int i = 0; i<4; i++)
		f << c.access[i];
	return f;
}
