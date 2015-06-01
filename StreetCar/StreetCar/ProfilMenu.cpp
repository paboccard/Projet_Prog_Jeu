#include "ProfilMenu.h"
#include "ui_ProfilMenu.h"
#include <QMessageBox>
#include <QtGui>

ProfilMenu::ProfilMenu(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ProfilMenu)
{
	ui->setupUi(this);
	QStringList avatar;
	avatar << "avatar1" << "avatar2" << "avatar3";
	ui->comboAvatar->addItems(avatar);
	ui->comboAvatar->setCurrentIndex(0);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(5);
    effect->setColor(QColor(255,0,0,255));
    effect->setOffset(1,1);
    ui->label->setGraphicsEffect(effect);
}

ProfilMenu::~ProfilMenu()
{
	delete ui;
}

QString ProfilMenu::getLineName(){
    return ui->lineName->text();
}

Profile ProfilMenu::getProfile(){
    return Profile(ui->lineName->text().toStdString(), ui->comboAvatar->currentIndex());
}

void ProfilMenu::on_buttonCreate_clicked()
{
	if (ui->lineName->text().isEmpty()) {
		QMessageBox::information(this, tr("Pas de nom"), tr("Remplir le champs Nom du joueur"));
	}
	else
		emit accepted(Profile(ui->lineName->text().toStdString(), ui->comboAvatar->currentIndex()));
}

void ProfilMenu::on_buttonCancel_clicked()
{
	emit rejected();
}
