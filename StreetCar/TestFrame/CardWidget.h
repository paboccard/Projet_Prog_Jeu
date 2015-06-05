#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QLabel>
#include "../Shared/Tile.h"
#include "UtilsGui.h"

class CardWidget : public QLabel, public Tile
{
	public:
		CardWidget(int i = 0);
		CardWidget(idTile t, int i = 0);
		void resizeEvent(QResizeEvent *e);
		int getIndex();
		void setEmpty();
		void changeTile(idTile t);
		void rotate();
		void updatePixmap();

		CardWidget &operator = (Tile &t);
		friend QDataStream& operator<<( QDataStream& f, CardWidget& c);
		friend QDataStream& operator>>( QDataStream& f, CardWidget& c);

	private:
		int index;
};

#endif // CARDWIDGET_H
