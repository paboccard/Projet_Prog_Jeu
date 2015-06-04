#include "HandWidget.h"
#include <QBoxLayout>
#include <QDebug>
#include <QDrag>
#include <QMimeData>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <QPainter>

using namespace std;

HandWidget::HandWidget(QWidget *parent) :
	QWidget(parent)
{
	//setBaseSize(80, 80);
	//setMaximumHeight(80);
	//setMaximumWidth(1500);
	//setMinimumSize(10, 10);
	srand (time(NULL));

	QHBoxLayout *layout = new QHBoxLayout();

	for (int i = 0; i < NBRTILEHAND; i ++) {
		cardWidget[i] = new CardWidget((idTile)(rand() % 12), i);
		layout->addWidget(cardWidget[i]);
	}

	setLayout(layout);
}

void HandWidget::resizeEvent(QResizeEvent *e)
{
	qDebug() << "resize hand" << e->size();
	//setMaximumWidth(e->size().width());
	//resizeEvent(e);
}

void HandWidget::cardDrop(int idx)
{
	*(Tile*)(cardWidget[idx]) = CardWidget(Empty);
	cardWidget[idx]->updatePixmap();
}

void HandWidget::cardChange(int idx, Tile t)
{
	*(Tile*)(cardWidget[idx]) = t;
	cardWidget[idx]->updatePixmap();
}

void HandWidget::dragEnterEvent(QDragEnterEvent *e)
{
	qDebug() << "drag enter hand";
	if (e->mimeData()->hasFormat("application/x-dnditemdata")) {
		if (e->source() == this) {
			qDebug() << "source";
			/*
			e->setDropAction(Qt::MoveAction);
			e->accept();
			*/
			e->ignore();
		} else {
			qDebug() << "not source";
			e->acceptProposedAction();
		}
	} else {
		e->ignore();
	}
}

void HandWidget::dragMoveEvent(QDragMoveEvent *e)
{
	qDebug() << "drag move hand";
	/*
	if (e->mimeData()->hasFormat("application/x-dnditemdata")) {
		if (e->source() == this) {
			if (child->coordinates.x < 3)
				e->ignore();
			else {

				e->setDropAction(Qt::MoveAction);
				e->accept();
			}
		} else {
			e->acceptProposedAction();
		}
	} else {
		e->ignore();
	}
*/
}

void HandWidget::dropEvent(QDropEvent *e)
{
	qDebug() << "Drop hand";

}

void HandWidget::mousePressEvent(QMouseEvent *e)
{
	CardWidget *child = static_cast<CardWidget *>(childAt(e->pos()));
	if (!child)
		return;
	switch(e->button()){
		case Qt::LeftButton:
			{
				qDebug() << "Card hand press";

				if (!child->isEmpty()) {
					qDebug() << child->getIndex();

					QByteArray itemData;

					QDataStream dataStream(&itemData, QIODevice::WriteOnly);
					dataStream << *child;

					cout << "++ " << endl;
					child->print();
					QMimeData *mimeData = new QMimeData();
					mimeData->setData("application/x-dnditemdata", itemData);

					QDrag *drag = new QDrag(this);
					drag->setMimeData(mimeData);
					drag->setPixmap(child->pixmap()->scaled(50, 50));
					drag->setHotSpot(QPoint(25, 25));

					QPixmap pixmap = *child->pixmap();
					QPainter p;
					p.begin(&pixmap);
					p.fillRect(pixmap.rect(), QColor(255, 255, 255, 100));
					child->setPixmap(pixmap);

					if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
						qDebug() << "move";
						//child->close();
					}
					else {
						qDebug() << "auther end";
						//child->show();
						child->updatePixmap();
					}
				}
			}
			break;
		case Qt::RightButton:
			child->rotate();
			break;
		default:
			break;
	}
}

