#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QDrag>
#include <QPushButton>
#include "../StreetCar/PlayerWidget.h"
#include "HandWidget.h"
#include "BoardView.h"
#include "../Shared/Player.h"
#include <QVector>
#include "../Shared/ProdCons.h"
#include "../Shared/PlayTile.h"


class GameWidget : public QWidget
{
		Q_OBJECT

	public:
		explicit GameWidget(QWidget *parent = 0);
		~GameWidget();
		void setPlayers(QVector<Player*> p);
		void setCurrentPlayer(int id);
		void setOutput(ProdCons<Pack*> *out);
		BoardView *getBoard();
		void setPlayedTil(Tile* t[]);
		void setPilePlayer(int idP, std::vector<Tile*> tile, std::vector<int> idx);



	public slots:
		void tileDrop(int);
		void tileChange(int, Tile);
		void undo();
		void redo();
		void playStroke();
		void strokeInvalid();

	protected:
		void mousePressEvent(QMouseEvent *e);

	private:
		Tile* currentStrok[2];
		int currentStrokIdx[2];
		int strokePlay;
		ProdCons<Pack*> *output;
		QVBoxLayout *layoutPlayer;
		int currentId;
		PlayerWidget **playerWidget;
		QVector<Player*> players;
		BoardView *board;
		HandWidget *hand;
		QPushButton *buttonUndo;
		QPushButton *buttonRedo;
		QPushButton *buttonPlay;
};

#endif // GAMEWIDGET_H
