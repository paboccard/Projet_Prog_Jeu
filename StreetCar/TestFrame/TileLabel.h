#ifndef TILELABEL_H
#define TILELABEL_H

#include <QLabel>
#include <QPixmap>
#include "../Shared/Tile.h"
#include <QPixmap>
#include <QResizeEvent>
#include <QDebug>
#include <QDataStream>
#include "UtilsGui.h"


class TileLabel : public QLabel, public Tile
{
		Q_OBJECT
	public:
		explicit TileLabel(QWidget *parent = 0, idTile i = Empty, int x = 0, int y = 0);
		~TileLabel();
		bool canMove;
/*
		bool getAccess(Orientation o) {return Tile::getAccess(o);}
		bool canChange(Square *s) {return Tile::canChange(s);}
		void rotate(int r = 1) {Tile::rotate(r);}
*/
		void setEmpty();
		void updatePixmap();

		//friend QDataStream& operator<<( QDataStream& f, TileLabel& c);
		friend QDataStream& operator>>( QDataStream& f, TileLabel& c);
	signals:

	public slots:

	private:
		void resizeEvent(QResizeEvent *e);
};

#endif // TILELABEL_H
