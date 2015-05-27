#ifndef NEWLOCALGAME_H
#define NEWLOCALGAME_H

#include <QWidget>

namespace Ui {
	class NewLocalGame;
}

class NewLocalGame : public QWidget
{
		Q_OBJECT

	public:
		explicit NewLocalGame(QWidget *parent = 0);
		~NewLocalGame();

	private slots:
		void on_buttonCancel_clicked();

		void on_buttonPlay_clicked();

		void on_buttonNewProfil_clicked();

	signals:
		void rejected();
		void accepted();
		void newProfil();

	private:
		Ui::NewLocalGame *ui;
};

#endif // NEWLOCALGAME_H
