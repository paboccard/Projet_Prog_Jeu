#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QDrag>
#include "HandWidget.h"
#include "../Shared/Player.h"


class GameWidget : public QWidget
{
		Q_OBJECT

	public:
		explicit GameWidget(QWidget *parent = 0);
		GameWidget(Player *p);
		~GameWidget();

	public slots:
		void action(Qt::DropAction a);

	protected:
		void mousePressEvent(QMouseEvent *e);
	private:
		Player *currentPlayer;
		QDrag *drag;
};

#endif // GAMEWIDGET_H
