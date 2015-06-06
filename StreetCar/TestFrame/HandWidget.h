#ifndef HANDWIDGET_H
#define HANDWIDGET_H

#include <QWidget>
#include <QDragEnterEvent>
#include <QHBoxLayout>
#include "CardWidget.h"
#include "UtilsGui.h"
#include "../Shared/Tile.h"

class HandWidget : public QWidget
{
		Q_OBJECT
	public:
		explicit HandWidget(QWidget *parent = 0);
		void resizeEvent(QResizeEvent* e);
		void setHand(Tile** t);
		void setMinSize(int s);
		void setDragAndDrop(bool d);
		Tile *getByIdx(int idx);

		CardWidget *getWidget(int i) {return cardWidget[i];};

	signals:

	public slots:
		void cardDrop(int idx);
		void cardChange(int idx, Tile t);

	private:
		CardWidget* cardWidget[5];
		//Tile **hand;
		QHBoxLayout *layout;
		bool dragAndDrop;

	protected:
		void mousePressEvent(QMouseEvent *e);
		void dropEvent(QDropEvent *e);
		void dragMoveEvent(QDragMoveEvent *e);
		void dragEnterEvent(QDragEnterEvent *e);
};

#endif // HANDWIDGET_H
