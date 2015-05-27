#include "ProfilMenu.h"
#include "ui_ProfilMenu.h"
#include <QMessageBox>

ProfilMenu::ProfilMenu(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ProfilMenu)
{
	ui->setupUi(this);
	QStringList avatar;
	avatar << "avatar1" << "avatar2" << "avatar3";
	ui->comboAvatar->addItems(avatar);
	ui->comboAvatar->setCurrentIndex(0);
}

ProfilMenu::~ProfilMenu()
{
	delete ui;
}

void ProfilMenu::on_buttonBox_accepted()
{
	/*if (ui->lineName->text().isEmpty()) {
		//QMessageBox::information(this, tr("Pas de nom"), tr("Veuiller renseigné votre nom"));
	}
	else*/
		emit accepted(Profile(ui->lineName->text().toStdString(), ui->comboAvatar->currentIndex()));
}

void ProfilMenu::on_buttonBox_rejected()
{
	emit rejected();
}
