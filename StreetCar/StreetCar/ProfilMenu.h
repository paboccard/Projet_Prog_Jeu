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

	private slots:
		void on_buttonBox_accepted();
		void on_buttonBox_rejected();

	signals:
		void accepted(Profile);
		void rejected();

	private:
		Ui::ProfilMenu *ui;
};

#endif // PROFILMENU_H