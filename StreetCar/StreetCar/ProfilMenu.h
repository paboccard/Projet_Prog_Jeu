#ifndef PROFILMENU_H
#define PROFILMENU_H

#include <QWidget>
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

	private slots:
		void on_buttonCreate_clicked();
		void on_buttonCancel_clicked();

signals:
		void accepted(Profile);
		void rejected();

	private:
		Ui::ProfilMenu *ui;
};

#endif // PROFILMENU_H
