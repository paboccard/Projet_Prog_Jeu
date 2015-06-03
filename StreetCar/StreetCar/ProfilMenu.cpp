#include "ProfilMenu.h"
#include "ui_ProfilMenu.h"
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QtGui>

ProfilMenu::ProfilMenu(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ProfilMenu)
{
	ui->setupUi(this);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
	effect->setBlurRadius(3);
    effect->setColor(QColor(255,0,0,255));
    effect->setOffset(1,1);
    ui->label->setGraphicsEffect(effect);

    ui->comboAvatar->setIconSize(QSize(100, 100));
    QVector<QIcon> avatarList;
    avatarList.push_back(QIcon(":/avatars/avatar1"));
    avatarList.push_back(QIcon(":/avatars/avatar2"));
    avatarList.push_back(QIcon(":/avatars/avatar3"));
    avatarList.push_back(QIcon(":/avatars/avatar4"));
    avatarList.push_back(QIcon(":/avatars/avatar5"));
    avatarList.push_back(QIcon(":/avatars/avatar6"));

    for(unsigned int i = 0; i < avatarList.size(); ++i){
        ui->comboAvatar->addItem(avatarList.at(i), QString(""));
    }
    ui->comboAvatar->setCurrentIndex(0);
}

ProfilMenu::~ProfilMenu()
{
	delete ui;
}

QString ProfilMenu::getLineName(){
    return ui->lineName->text();
}

void ProfilMenu::hideModifyButton(){
	return ui->buttonModify->hide();
}

void ProfilMenu::showModifyButton(){
	return ui->buttonModify->show();
}

Profile ProfilMenu::getProfile(){
	return Profile(ui->lineName->text().toStdString(), ui->comboAvatar->currentIndex(), 1);
}

void ProfilMenu::on_buttonCreate_clicked()
{
	if (ui->lineName->text().isEmpty()) {
		QMessageBox::information(this, tr("Pas de nom"), tr("Remplir le champs Nom du joueur"));
	}
	else{

		emit accepted(Profile(ui->lineName->text().toStdString(), ui->comboAvatar->currentIndex(), 1));

	}
}

void ProfilMenu::on_buttonCancel_clicked()
{
	emit rejected();
}

void ProfilMenu::on_buttonModify_clicked()
{
	emit accepted(Profile(ui->lineName->text().toStdString(), ui->comboAvatar->currentIndex(), 1));
}
