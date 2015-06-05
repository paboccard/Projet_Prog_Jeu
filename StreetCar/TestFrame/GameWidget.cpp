#include "GameWidget.h"
#include <QBoxLayout>
#include <QDebug>
#include <iostream>

using namespace std;

GameWidget::GameWidget(QWidget *parent) :
	QWidget(parent)
{
	setAcceptDrops(true);
	QVBoxLayout *layout = new QVBoxLayout(this);

	board = new BoardView();
	hand = new HandWidget();
	layout->addWidget(board);
	layout->addWidget(hand);

	connect(board, SIGNAL(tileDrop(int)), hand, SLOT(cardDrop(int)));
	connect(board, SIGNAL(tileChange(int,Tile)), hand, SLOT(cardChange(int,Tile)));

	setLayout(layout);
	//setBaseSize(100, 100);
	resize(100, 100);
}

GameWidget::~GameWidget()
{
}

void GameWidget::setPlayers(QVector<Player *> p)
{
	players = p;
	//cout << "my hand : ";
	//hand->setHand(p[myId-1]->getHand());
}

void GameWidget::setCurrentPlayer(int id)
{
	currentId = id;
	hand->setHand(players[currentId]->getHand());
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