#ifndef PROFILMENU_H
#define PROFILMENU_H

#include <QWidget>
#include <QPushButton>
#include "../Shared/Profile.h"

namespace Ui {
	class ProfilMenu;
}

class ProfilMenu : public QWidget
{
		Q_OBJECT

	public:
		explicit ProfilMenu(QWidget *parent = 0);
		~ProfilMenu();
        QString getLineName();
        Profile getProfile();
		void hideModifyButton();
		void showModifyButton();

	private slots:
		void on_buttonCreate_clicked();
		void on_buttonCancel_clicked();
		void on_buttonModify_clicked();

signals:
		void accepted(Profile);
		void rejected();

	private:
		Ui::ProfilMenu *ui;
};

#endif // PROFILMENU_H
