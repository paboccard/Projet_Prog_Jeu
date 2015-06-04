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
		void clear();
        Profile getProfile();
		QVector<Profile> *getProfiles();
		void hideCreateButton();
		void showCreateButton();
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
		QVector<Profile> *profiles;
};

#endif // PROFILMENU_H
