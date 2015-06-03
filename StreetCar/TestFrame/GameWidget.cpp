#include "GameWidget.h"
#include <QBoxLayout>
#include <QDebug>

GameWidget::GameWidget(QWidget *parent) :
	QWidget(parent)
{
	setAcceptDrops(true);
	QVBoxLayout *layout = new QVBoxLayout();

	board = new BoardView();
	hand = new HandWidget();
	layout->addWidget(board);
	layout->addWidget(hand);

	setLayout(layout);
}

GameWidget::~GameWidget()
{
}

BoardView *GameWidget::getBoard()
{
	return board;
}

void GameWidget::mousePressEvent(QMouseEvent *e)
{
	/*
	TileLabel *child = static_cast<TileLabel *>(childAt(e->pos()));
	if (!child)
		return;


	QPixmap pixmap = *child->pixmap();

	QByteArray itemData;

	QDataStream dataStream(&itemData, QIODevice::WriteOnly);
	dataStream << QPoint(e->pos() - child->pos()) << Tile;

	QMimeData *mimeData = new QMimeData();
	mimeData->setData("application/x-dnditemdata", itemData);

	drag = new QDrag(this);
	drag->setMimeData(mimeData);
	drag->setPixmap(pixmap.scaled(50, 50));
	//drag->setHotSpot(e->pos()-child->pos());
	drag->setHotSpot(QPoint(25, 25));
	connect(drag, SIGNAL(actionChanged(Qt::DropAction)), this, SLOT(action(Qt::DropAction)));

	//drag->exec(Qt::MoveAction, Qt::MoveAction);
	if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction)
		child->close();
	else {
		child->show();
		child->setPixmap(pixmap);
	}
	*/
}
