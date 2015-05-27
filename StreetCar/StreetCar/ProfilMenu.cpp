#include "ProfilMenu.h"
#include "ui_ProfilMenu.h"

ProfilMenu::ProfilMenu(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ProfilMenu)
{
	ui->setupUi(this);
}

ProfilMenu::~ProfilMenu()
{
	delete ui;
}

void ProfilMenu::on_buttonBox_accepted()
{
	emit accepted();
}

void ProfilMenu::on_buttonBox_rejected()
{
	emit rejected();
}
