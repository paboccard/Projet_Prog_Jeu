#ifndef NEWLOCALGAME_H
#define NEWLOCALGAME_H

#include <QWidget>
#include "../Shared/Profile.h"
#include "ProfilMenu.h"
#include <QTableWidgetItem>

namespace Ui {
	class NewLocalGame;
}

class NewLocalGame : public QWidget
{
		Q_OBJECT

	public:
		explicit NewLocalGame(QWidget *parent = 0);
		~NewLocalGame();
		QTableWidgetItem* getItemName();
		QTableWidgetItem* getItemAvatar();

	private slots:
		void on_buttonCancel_clicked();
		void on_buttonPlay_clicked();
		void on_buttonNewProfil_clicked();
        void on_spinNbPlayer_valueChanged(int arg1);

signals:
		void rejected();
		void accepted(int);
		void newProfil();

	private:
		Ui::NewLocalGame *ui;
        ProfilMenu *profilMenu;
        Profile currentProfile;
};

#endif // NEWLOCALGAME_H
