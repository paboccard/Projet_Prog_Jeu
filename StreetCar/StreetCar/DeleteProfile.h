#ifndef DELETEPROFILE_H
#define DELETEPROFILE_H

#include <QWidget>
#include "ProfilMenu.h"

namespace Ui {
class DeleteProfile;
}

class DeleteProfile : public QWidget
{
	Q_OBJECT

public:
	explicit DeleteProfile(QWidget *parent = 0);
	~DeleteProfile();

private slots:
	void on_buttonDelete_clicked();
	void on_buttonCancel_clicked();

signals:
		void accepted(Profile);
		void rejected();

private:
	Ui::DeleteProfile *ui;
};

#endif // DELETEPROFILE_H
