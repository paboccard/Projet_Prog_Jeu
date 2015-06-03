#include "BoardView.h"
#include <QDebug>
#include <QMimeData>
#include <QByteArray>
#include <QDataStream>
#include <QDrag>
#include <QPainter>
#include <cstdlib>
#include <time.h>
#include <sstream>

using namespace std;

BoardView::BoardView()
	: QFrame(), Board()
{
	setMinimumSize(TILESIZE * getSize(), TILESIZE * getSize());

	setAcceptDrops(true);
	srand (time(NULL));
/*
	for (int i = 0; i < getSize(); i ++) {

		for (int j = 0; j < getSize(); j ++)
		{
			if (get(i, j)->isEmpty())
				get(i, j)->setType((idTile)((rand() % 15) -1));
			qDebug() << "create " << i << " " << j << " " << get(i, j)->getType();
			TileLabel *t = new TileLabel(this, i, j, get(i, j)->getType());
			t->move(i*TILESIZE, j*TILESIZE);
		}
	}
	*/
	initEmpty();
}

BoardView::~BoardView()
{

}

void BoardView::initEmpty()
{
	setSize(14, 12);
	setMinimumSize(TILESIZE * getSize(), TILESIZE * getSize());

	for(int i = 0; i < getSize()-1; i++){
		changeSquare(new TileLabel(this, Wall, 0, i));
		changeSquare(new TileLabel(this, Wall, getSize()-1, i+1));
		changeSquare(new TileLabel(this, Wall, i+1, 0));
		changeSquare(new TileLabel(this, Wall, i, getSize()-1));
	}

	for (int i = 1; i < getSize()-1; i ++) {
		for (int j = 1; j < getSize()-1; j ++)
			changeSquare(new TileLabel(this, Empty, i, j));
	}


	changeSquare(new TileLabel(this, Terminus4_1, 0, 2));
	changeSquare(new TileLabel(this, Terminus4_2,0,3));
	changeSquare(new TileLabel(this, Terminus5_1,0,6));
	changeSquare(new TileLabel(this, Terminus5_2,0,7));
	changeSquare(new TileLabel(this, Terminus6_1,0,10));
	changeSquare(new TileLabel(this, Terminus6_2,0,11));

	changeSquare(new TileLabel(this, Terminus3_2,2,0));
	changeSquare(new TileLabel(this, Terminus3_1,3,0));
	changeSquare(new TileLabel(this, Terminus2_2,6,0));
	changeSquare(new TileLabel(this, Terminus2_1,7,0));
	changeSquare(new TileLabel(this, Terminus1_2,10,0));
	changeSquare(new TileLabel(this, Terminus1_1,11,0));

	changeSquare(new TileLabel(this, Terminus6_4,13,2));
	changeSquare(new TileLabel(this, Terminus6_3,13,3));
	changeSquare(new TileLabel(this, Terminus4_4,13,6));
	changeSquare(new TileLabel(this, Terminus4_3,13,7));
	changeSquare(new TileLabel(this, Terminus5_4,13,10));
	changeSquare(new TileLabel(this, Terminus5_3,13,11));

	changeSquare(new TileLabel(this, Terminus2_3,2,13));
	changeSquare(new TileLabel(this, Terminus2_4,3,13));
	changeSquare(new TileLabel(this, Terminus1_3,6,13));
	changeSquare(new TileLabel(this, Terminus1_4,7,13));
	changeSquare(new TileLabel(this, Terminus3_3,10,13));
	changeSquare(new TileLabel(this, Terminus3_4,11,13));

	stations[0] = new StationWidget(this, StationC, 8, 1);
	stations[1] = new StationWidget(this, StationB, 4, 2);
	stations[2] = new StationWidget(this, StationK, 6, 4);
	stations[3] = new StationWidget(this, StationD, 11, 4);
	stations[4] = new StationWidget(this, StationA, 1, 5);
	stations[5] = new StationWidget(this, StationL, 9, 6);
	stations[6] = new StationWidget(this, StationI, 4, 7);
	stations[7] = new StationWidget(this, StationE, 12, 8);
	stations[8] = new StationWidget(this, StationH, 2, 9);
	stations[9] = new StationWidget(this, StationM, 7, 9);
	stations[10] = new StationWidget(this, StationF, 9, 11);
	stations[11] = new StationWidget(this, StationG, 5, 12);

	for (int i = 0; i < nbrStation; i ++)
		changeSquare(stations[i]);
}

void BoardView::resizeEvent(QResizeEvent *e)
{
	qDebug() << "board resize" << e->size();
}

void BoardView::dragEnterEvent(QDragEnterEvent *e)
{
	qDebug() << "drag enter board";
	if (e->mimeData()->hasFormat("application/x-dnditemdata")) {
		if (e->source() == this) {
			qDebug() << "source";


			TileLabel *child = static_cast<TileLabel *>(childAt(e->pos()));
			if (!child)
					return;
			e->setDropAction(Qt::MoveAction);
			e->accept();
		} else {
			qDebug() << "no source";
			e->acceptProposedAction();
		}
	} else {
		e->ignore();
	}
}

void BoardView::dragMoveEvent(QDragMoveEvent *e)
{
	qDebug() << "drag move board";
	TileLabel *child = static_cast<TileLabel *>(childAt(e->pos()));
	if (!child)
			return;

	if (e->mimeData()->hasFormat("application/x-dnditemdata")) {
		if (e->source() == this) {
			qDebug() << "source";
			if (child->getCoordinates().x < 3)
				e->ignore();
			else {

				e->setDropAction(Qt::MoveAction);
				e->accept();
			}
		} else {
			qDebug() << "no source";
			TileLabel *child = static_cast<TileLabel *>(childAt(e->pos()));
			if (!child) {
				e->ignore();
				return;
			}

			QByteArray itemData = e->mimeData()->data("application/x-dnditemdata");
			QDataStream dataStream(&itemData, QIODevice::ReadOnly);

			CardWidget h;
			dataStream >> h;

			/*if (child->isEmpty()) {
				qDebug() << "is empty";
				if (putPossible(child->getCoordinates(), &h)) {
					qDebug() << "put possible";
					e->acceptProposedAction();
				}
				else {
					qDebug() << "put impossible";
					e->ignore();
				}
			}
			else {
				qDebug() << "not empty";
				if (changePossible(child, &h)) {
					qDebug() << "change possible";
					e->acceptProposedAction();
				}
				else {
					qDebug() << "change impossible";
					e->ignore();
				}
			}*/

			if ((child->isEmpty() && putPossible(child->getCoordinates(), &h)) ||
				(!child->isEmpty() && changePossible(child, &h))) {
				e->acceptProposedAction();
			}
			else
				e->ignore();



/*
			int t;
			int id;
			int turn;
			dataStream >> t >> id >> turn;

			if (t == HAND) {
				Tile *t = new Tile((idTile)id, child->getCoordinates().x, child->getCoordinates().y);
				t->rotate(turn);
				qDebug() << id;
				if ((child->isEmpty() && putPossible(child->getCoordinates(), t)) ||
					(child->isTile() && changePossible(child, t))) {
					e->acceptProposedAction();
				}
				else
					e->ignore();
				delete t;

			}
			else
				e->acceptProposedAction();
				*/
		}
	} else {
		e->ignore();
	}

}

void BoardView::dropEvent(QDropEvent *e)
{
	qDebug() << "Drop board";
	TileLabel *child = static_cast<TileLabel *>(childAt(e->pos()));
	if (!child)
		return;
	if (e->mimeData()->hasFormat("application/x-dnditemdata")) {
		QByteArray itemData = e->mimeData()->data("application/x-dnditemdata");
		QDataStream dataStream(&itemData, QIODevice::ReadOnly);

		TileLabel *tileLabel = new TileLabel(this);
		dataStream >> *tileLabel;

		if (child->isEmpty() && putPossible(child->getCoordinates(), tileLabel)) {
			set(child->getCoordinates().x, child->getCoordinates().y, tileLabel);
			tileLabel->updatePixmap();
			tileLabel->move(tileLabel->getCoordinates().x*TILESIZE, tileLabel->getCoordinates().y*TILESIZE);
			tileLabel->show();

			delete child;
			e->setDropAction(Qt::MoveAction);
		}
		else if (!child->isEmpty() && changePossible(child, tileLabel)) {

			set(child->getCoordinates().x, child->getCoordinates().y, tileLabel);
			tileLabel->updatePixmap();
			tileLabel->move(tileLabel->getCoordinates().x*TILESIZE, tileLabel->getCoordinates().y*TILESIZE);
			tileLabel->show();

			delete child;
			e->setDropAction(Qt::MoveAction);
		}
		else
			e->ignore();

	} else {
		e->ignore();
	}

}

void BoardView::mousePressEvent(QMouseEvent *e)
{
	/*
	qDebug() << "press";
	TileLabel *child = static_cast<TileLabel *>(childAt(e->pos()));
	if (!child)
		return;

	if (child->canMove) {

		QPixmap pixmap = *child->pixmap();

		QByteArray itemData;

	//	QDataStream dataStream(&itemData, QIODevice::WriteOnly);
	//	dataStream << child->getType() << child->getTurn();


		child->setEmpty();

		QMimeData *mimeData = new QMimeData();
		mimeData->setData("application/x-dnditemdata", itemData);

		QDrag *drag = new QDrag(this);
		drag->setMimeData(mimeData);
		drag->setPixmap(pixmap);
		drag->setHotSpot(e->pos()-child->pos());

		//drag->exec(Qt::MoveAction, Qt::MoveAction);
		if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction)
			child->close();
		else {
			child->show();
			child->setPixmap(pixmap);
		}
	}*/
}

void BoardView::setSquare(Square *s)
{
	//qDebug() << "set";
	Board::setSquare(s);
	((TileLabel*)s)->move(s->getCoordinates().x*TILESIZE, s->getCoordinates().y*TILESIZE);
}

void BoardView::changeSquare(Square *s)
{
	//qDebug() << "change";
	Board::changeSquare(s);
	((TileLabel*)s)->move(s->getCoordinates().x*TILESIZE, s->getCoordinates().y*TILESIZE);
}
