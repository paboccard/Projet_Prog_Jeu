#include "GameWidget.h"
#include <QBoxLayout>
#include <QDebug>
#include <QPropertyAnimation>
#include <iostream>
#include "PlayerWidget.h"

using namespace std;

GameWidget::GameWidget(QWidget *parent) :
	QWidget(parent)
{
	setAcceptDrops(true);
	QVBoxLayout *mainLayout = new QVBoxLayout();
	QHBoxLayout *layout = new QHBoxLayout();
	layout->setAlignment(Qt::AlignLeft);
	QHBoxLayout *layoutCard = new QHBoxLayout();
	QHBoxLayout *layoutBottom = new QHBoxLayout();

	playerContenerWidget = new QWidget();
	layoutPlayer = new QVBoxLayout(playerContenerWidget);
	layoutPlayer->setAlignment(Qt::AlignTop | Qt::AlignLeft);

	board = new BoardView();

	layout->addWidget(playerContenerWidget);
	layout->addWidget(board);

	QHBoxLayout *layoutUndoRedo = new QHBoxLayout();
	layoutUndoRedo->setAlignment(Qt::AlignRight);

	buttonUndo = new QPushButton(tr("Annuler"));
	buttonRedo = new QPushButton(tr("Refaire"));

	buttonPlay = new QPushButton(tr("Valider le coup"));
	layoutUndoRedo->addWidget(buttonUndo);
	layoutUndoRedo->addWidget(buttonRedo);
	layoutUndoRedo->addWidget(buttonPlay);

	stopCard = new GoalCard();
	lineCard = new GoalCard();

	layoutCard->addWidget(lineCard);
	layoutCard->addWidget(stopCard);

	QFrame *frame = new QFrame();
	frame->setFrameShape(QFrame::VLine);
	frame->setFrameShadow(QFrame::Sunken);
	//frame->setFrameShape(QFrame::WinPanel);
	//frame->setFrameShadow(QFrame::Raised);
	layoutCard->addWidget(frame);

	layoutBottom->addLayout(layoutCard);
	hand = new HandWidget();
	layoutBottom->addWidget(hand);
	layoutBottom->setStretch(1, 10);


	currentStrok[0] = new Tile();
	currentStrok[1] = new Tile();

	mainLayout->addLayout(layout);
	mainLayout->addLayout(layoutUndoRedo);
	mainLayout->addLayout(layoutBottom);


	connect(board, SIGNAL(tileDrop(int)), this, SLOT(tileDrop(int)));
	connect(board, SIGNAL(tileChange(int,Tile)), this, SLOT(tileChange(int,Tile)));
	connect(buttonUndo, SIGNAL(clicked()), this, SLOT(undo()));
	connect(buttonRedo, SIGNAL(clicked()), this, SLOT(redo()));
	connect(buttonPlay, SIGNAL(clicked()), this, SLOT(playStroke()));
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
	board->resetStroke();
	buttonUndo->setEnabled(false);
	buttonRedo->setEnabled(false);
	buttonPlay->setEnabled(false);


	currentId = id;
	strokePlay = 0;
	cout << "G: new hand player: ---------------";
	for (int i = 0; i < 5; i ++)
		cout <<players[currentId]->getHand()[i]->getType() << " ";
	cout << endl;
	hand->setHand(players[currentId]->getHand());

	cout << "poc1" << endl;
	if (myPlayers.indexOf(currentId) >= 0)	{ //the current player is my player
		hand->setDragAndDrop(true);
		lineCard->setPixmapToShow(QPixmap(":/cards/carteArrets"+QString::number(players[currentId]->getLine()+1)));
		stopCard->setPixmapToShow(QPixmap(":/cards/carteArrets"+QString::number(players[currentId]->getStopCard()+7)));
		lineCard->setEnabled(true);
		stopCard->setEnabled(true);
	}
	else { //the current player doesn't play here
		hand->setDragAndDrop(false);
		lineCard->setEnabled(false);
		stopCard->setEnabled(false);
	}
	cout << "poc2" << endl;
	/*
	QPropertyAnimation *anim = new QPropertyAnimation(hand->getWidget(2), "geometry");
	anim->setDuration(10000);
	anim->setStartValue(QRect(0, 0, 80, 80));
	anim->setEndValue(QRect(200, 200, 40, 40));
	anim->start();
	*/
}

void GameWidget::setOutput(ProdCons<Pack *> *out)
{
	output = out;
}

BoardView *GameWidget::getBoard()
{
	return board;
}

void GameWidget::setPlayedTil(Tile *t[])
{
	for (int i = 0; i < 2; i ++)
		board->set(t[i]);
}

void GameWidget::setPilePlayer(int idP, std::vector<Tile*> tile, std::vector<int> idx)
{
	for (int i = 0; i < tile.size(); i ++)
		players[idP]->setHand(tile[i], idx[i]);

	playerWidget[idP]->updateHand();
}

void GameWidget::setMyPlayers(QVector<int> p)
{
	myPlayers = p;
}

void GameWidget::tileDrop(int idx)
{
	*currentStrok[strokePlay] = board->getLastTile();
	currentStrokIdx[strokePlay] = idx;
	strokePlay ++;
	cout << "G: Play: " << board->getLastTile().getType() << endl;
	buttonUndo->setEnabled(true);
	buttonRedo->setEnabled(false);

	if (strokePlay >= 2) {
		hand->setDragAndDrop(false);
		buttonPlay->setEnabled(true);
	}
	hand->cardDrop(idx);

}

void GameWidget::tileChange(int idx, Tile t)
{
	*currentStrok[strokePlay] = board->getLastTile();
	currentStrokIdx[strokePlay] = idx;
	strokePlay ++;
	cout << "G: Play: " << board->getLastTile().getType() << endl;
	buttonUndo->setEnabled(true);
	buttonRedo->setEnabled(false);
	if (strokePlay >= 2) {
		hand->setDragAndDrop(false);
		buttonPlay->setEnabled(true);
	}
	hand->cardChange(idx, t);

}

void GameWidget::undo()
{
	strokePlay --;
	board->undoStroke();
	board->update();
	hand->update();
	if (!board->canUndo())
		buttonUndo->setEnabled(false);
	buttonRedo->setEnabled(true);
	hand->setDragAndDrop(true);
	buttonPlay->setEnabled(false);

}

void GameWidget::redo()
{
	strokePlay ++;
	cout << "redo" << endl;
	board->redoStroke();
	board->update();
	hand->update();
	if (!board->canRedo())
		buttonRedo->setEnabled(false);
	buttonUndo->setEnabled(true);
	if (strokePlay >= 2) {
		hand->setDragAndDrop(false);
		buttonPlay->setEnabled(true);
	}
}

void GameWidget::playStroke()
{
	buttonPlay->setEnabled(false);
	if (strokePlay >= 2) {
		cout << "G: Player hand to play: ---------------";
		for (int i = 0; i < 5; i ++)
			cout << players[currentId]->getHand()[i]->getType() << " ";
		cout << endl;
		output->produce(new PlayTile(currentId, currentStrok, currentStrokIdx));
	}
	else
		cout << "G: ERROR, impossible to play stroke, stroke play: " << strokePlay << endl;

}

void GameWidget::strokeInvalid()
{
	while (board->canRedo())
		redo();
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
