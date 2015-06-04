#ifndef HANDWIDGET_H
#define HANDWIDGET_H

#include <QWidget>
#include <QDragEnterEvent>
#include "CardWidget.h"
#include "UtilsGui.h"

#define NBRTILEHAND 5

class HandWidget : public QWidget
{
		Q_OBJECT
	public:
		explicit HandWidget(QWidget *parent = 0);
		void resizeEvent(QResizeEvent* e);
		void setCard(int idx, Tile t);
	signals:

	public slots:
		void cardDrop(int idx);
		void cardChange(int idx, Tile t);

	private:
		CardWidget *cardWidget[NBRTILEHAND];

	protected:
		void mousePressEvent(QMouseEvent *e);
		void dropEvent(QDropEvent *e);
		void dragMoveEvent(QDragMoveEvent *e);
		void dragEnterEvent(QDragEnterEvent *e);
};

#endif // HANDWIDGET_H
