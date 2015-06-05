#include "GameWidget.h"
#include <QBoxLayout>
#include <QDebug>
#include <iostream>
#include "PlayerWidget.h"

using namespace std;

GameWidget::GameWidget(QWidget *parent) :
	QWidget(parent)
{
	setAcceptDrops(true);
	QVBoxLayout *mainLayout = new QVBoxLayout();
	QHBoxLayout *layout = new QHBoxLayout();
	layoutPlayer = new QVBoxLayout();

	layoutPlayer->setAlignment(Qt::AlignTop | Qt::AlignLeft);

	board = new BoardView();
	layout->addLayout(layoutPlayer);
	layout->addWidget(board);

	hand = new HandWidget();

	currentStrok[0] = new Tile();
	currentStrok[1] = new Tile();


	mainLayout->addLayout(layout);
	mainLayout->addWidget(hand);


	connect(board, SIGNAL(tileDrop(int)), this, SLOT(tileDrop(int)));
	connect(board, SIGNAL(tileChange(int,Tile)), this, SLOT(tileChange(int,Tile)));
	board->resetStroke();

	setLayout(mainLayout);
	resize(100, 100);
}

GameWidget::~GameWidget()
{
}

void GameWidget::setPlayers(QVector<Player *> p)
{
	players = p;
	playerWidget = new PlayerWidget*[p.size()];

	for (int i = 0; i < p.size(); i ++) {
		playerWidget[i] = new PlayerWidget(p[i]);
		//PlayerWidget *player = new PlayerWidget();
		layoutPlayer->addWidget(playerWidget[i]);
	}


	//cout << "my hand : ";
	//hand->setHand(p[myId-1]->getHand());
}

void GameWidget::setCurrentPlayer(int id)
{
	hand->setDragAndDrop(true);
	board->resetStroke();
	currentId = id;
	strokePlay = 0;
	hand->setHand(players[currentId]->getHand());
}

void GameWidget::setOutput(ProdCons<Pack *> *out)
{
	output = out;
}

BoardView *GameWidget::getBoard()
{
	return board;
}

void GameWidget::tileDrop(int idx)
{
	*currentStrok[strokePlay] = board->getLastTile();
	currentStrokIdx[strokePlay] = idx;
	strokePlay ++;
	hand->cardDrop(idx);
	if (strokePlay >= 2){
		hand->setDragAndDrop(false);
		output->produce(new PlayTile(currentId, currentStrok, currentStrokIdx));
	}
}

void GameWidget::tileChange(int idx, Tile t)
{
	*currentStrok[strokePlay] = board->getLastTile();
	currentStrokIdx[strokePlay] = idx;
	strokePlay ++;
	hand->cardChange(idx, t);
	if (strokePlay >= 2) {
		hand->setDragAndDrop(false);
		output->produce(new PlayTile(currentId, currentStrok, currentStrokIdx));
	}
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
