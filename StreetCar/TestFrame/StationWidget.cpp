#include "StationWidget.h"
#include <QResizeEvent>
#include <QDebug>

StationWidget::StationWidget(QWidget *parent, idTile s, int x, int y) : QLabel(parent), Station(s, x, y)
{
	//setMaximumSize(TILESIZE-1, TILESIZE-1);
	//setMinimumSize(TILESIZE-1, TILESIZE-1);
	setPixmap(getPixmap(s));

	setAttribute(Qt::WA_DeleteOnClose);
	updatePixmap();
}

StationWidget::~StationWidget()
{

}

void StationWidget::updatePixmap()
{
	setPixmap(getPixmap(getType()).scaled(width(), height(), Qt::KeepAspectRatio));
}

void StationWidget::resizeEvent(QResizeEvent *e)
{
	qDebug() << "label resize Station";
	int min;
	if (e->size().width() < e->size().height())
		min = e->size().width();
	else
		min = e->size().height();
	setMaximumSize(min, min);
	setMinimumSize(min, min);
	updatePixmap();
	//setPixmap(pixmap()->scaled(e->size(), Qt::KeepAspectRatio));
}
