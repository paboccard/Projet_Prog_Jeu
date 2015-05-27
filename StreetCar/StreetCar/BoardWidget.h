#ifndef BOARD_H
#define BOARD_H

#include <QWidget>

namespace Ui {
	class Board;
}

class BoardWidget : public QWidget
{
		Q_OBJECT

	public:
		explicit BoardWidget(QWidget *parent = 0);
		~BoardWidget();

	private:
		Ui::Board *ui;
};

#endif // BOARD_H
