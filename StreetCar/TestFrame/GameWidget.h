#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QDrag>
#include "HandWidget.h"
#include "BoardView.h"
#include "../Shared/Player.h"


class GameWidget : public QWidget
{
		Q_OBJECT

	public:
		explicit GameWidget(QWidget *parent = 0);
		~GameWidget();

		BoardView *getBoard();

	public slots:

	protected:
		void mousePressEvent(QMouseEvent *e);
	private:
		BoardView *board;
		HandWidget *hand;
};

#endif // GAMEWIDGET_H
