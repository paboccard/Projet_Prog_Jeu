#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QDrag>
#include "HandWidget.h"
#include "BoardView.h"
#include "../Shared/Player.h"
#include <QVector>


class GameWidget : public QWidget
{
		Q_OBJECT

	public:
		explicit GameWidget(QWidget *parent = 0);
		~GameWidget();
		void setPlayers(QVector<Player*> p);
		void setCurrentPlayer(int id);

		BoardView *getBoard();

	public slots:

	protected:
		void mousePressEvent(QMouseEvent *e);
	private:
		int currentPlayer;
		int currentId;
		QVector<Player*> players;
		BoardView *board;
		HandWidget *hand;
};

#endif // GAMEWIDGET_H
