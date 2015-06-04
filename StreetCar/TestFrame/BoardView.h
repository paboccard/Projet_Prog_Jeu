#ifndef BOARDVIEW_H
#define BOARDVIEW_H
#include <QObject>
#include <QFrame>
#include <QLabel>
#include <QPixmap>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QMouseEvent>
#include <QGridLayout>
#include "TileLabel.h"
#include "UtilsGui.h"
#include "StationWidget.h"
#include "HandWidget.h"
#include "../Shared/Board.h"


class BoardView : public QFrame, public Board
{
	Q_OBJECT
	public:
		BoardView();
		~BoardView();

		void initEmpty();
		void resizeEvent(QResizeEvent *e);
		void change(TileLabel *sBoard, TileLabel *sHand);
		void put(TileLabel *sBoard, TileLabel *sHand);
		void put(TileLabel *t);

	signals:
		void tileDrop(int);
		void tileChange(int, Tile);

	private:

		QGridLayout *layout;

	protected:
		void dragEnterEvent(QDragEnterEvent *e);
		void dragMoveEvent(QDragMoveEvent *e);
		void dropEvent(QDropEvent *e);
		void mousePressEvent(QMouseEvent *e);

		void setSquare(Square *s);
		void changeSquare(Square *s);
};

#endif // BOARDVIEW_H
