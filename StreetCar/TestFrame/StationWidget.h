#ifndef STATIONWIDGET_H
#define STATIONWIDGET_H

#include <QLabel>
#include <QPixmap>
#include "UtilsGui.h"
#include "../Shared/Station.h"

class StationWidget : public QLabel, public Station
{
	public:
		StationWidget(QWidget *parent = 0, idTile s = StationA, int x = -1, int y = -1);
		~StationWidget();

		void updatePixmap();

	private:
		void resizeEvent(QResizeEvent *e);

};

#endif // STATIONWIDGET_H
