#include "ProfilMenu.h"
#include "ui_ProfilMenu.h"
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QtGui>
#include <iostream>

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

	profiles = new QVector<Profile>;
}

ProfilMenu::~ProfilMenu()
{
	delete ui;
}

QString ProfilMenu::getLineName(){
    return ui->lineName->text();
}

void ProfilMenu::clear(){
	ui->lineName->clear();
	ui->comboAvatar->setCurrentIndex(0);
}

void ProfilMenu::currentProfile(){
	ui->lineName->setText(profiles->at(0).name.c_str());
	ui->comboAvatar->setCurrentIndex(profiles->at(0).avatar);
}

QVector<Profile> *ProfilMenu::getProfiles(){
	return profiles;
}

void ProfilMenu::hideModifyButton(){
	return ui->buttonModify->hide();
}

void ProfilMenu::showModifyButton(){
	return ui->buttonModify->show();
}

void ProfilMenu::show()
{
	ui->lineName->setFocus();
	QWidget::show();
}

void ProfilMenu::hideCreateButton(){
	return ui->buttonCreate->hide();
}

void ProfilMenu::showCreateButton(){
	return ui->buttonCreate->show();
}

Profile ProfilMenu::getProfile(){
	return Profile(ui->lineName->text().toStdString(), ui->comboAvatar->currentIndex(), 0);
}

void ProfilMenu::on_buttonCreate_clicked()
{
	for (unsigned int i = 0; i < profiles->size(); i++){
		if((ui->lineName->text().toStdString() == profiles->at(i).name) && (ui->comboAvatar->currentIndex() == profiles->at(i).avatar)){
            QMessageBox::information(this, tr("Profil existant"), tr("Choisir un autre Nom de joueur ou Avatar"));
		}
	}
	if (ui->lineName->text().isEmpty()) {
		QMessageBox::information(this, tr("Pas de nom"), tr("Remplir le champs Nom du joueur"));
	}else{

		emit accepted(Profile(ui->lineName->text().toStdString(), ui->comboAvatar->currentIndex(), 0));
	}
}

void ProfilMenu::on_buttonCancel_clicked()
{
	emit rejected();
}

void ProfilMenu::on_buttonModify_clicked()
{
	//gestion existing profile
	if((ui->lineName->text().toStdString() == profiles->at(0).name) && (ui->comboAvatar->currentIndex() == profiles->at(0).avatar)){
        QMessageBox::information(this, tr("Profil identique"), tr("Le profil est identique"));
	}else{
		emit modified(Profile(ui->lineName->text().toStdString(), ui->comboAvatar->currentIndex(), 0));
	}
}

void ProfilMenu::on_lineName_returnPressed()
{
	if (ui->buttonModify->isVisible())
		ui->buttonModify->click();
	else if (ui->buttonCreate->isVisible())
		ui->buttonCreate->click();
}
