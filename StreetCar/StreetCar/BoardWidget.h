#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

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

private slots:
	void on_buttonHelp_clicked();
	void on_buttonStartTravel_clicked();
	void on_buttonSave_clicked();
	void on_buttonExit_clicked();

signals:
	void helped();
	void startedTravel();
	void saved();
	void exitGame();

private:
		Ui::Board *ui;
};

#endif // BOARDWIDGET_H
