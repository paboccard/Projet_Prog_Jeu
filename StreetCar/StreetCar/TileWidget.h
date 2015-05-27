#ifndef TILEWIDGET_H
#define TILEWIDGET_H

#include <QWidget>

namespace Ui {
class TileWidget;
}

class TileWidget : public QWidget
{
		Q_OBJECT

	public:
		explicit TileWidget(QWidget *parent = 0);
		~TileWidget();

	private:
		Ui::TileWidget *ui;
};

#endif // TILEWIDGET_H
