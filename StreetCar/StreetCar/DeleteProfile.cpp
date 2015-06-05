#include "DeleteProfile.h"
#include "ui_DeleteProfile.h"
#include <QtGui>
#include <iostream>

DeleteProfile::DeleteProfile(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::DeleteProfile)
{
	ui->setupUi(this);

	QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
	effect->setBlurRadius(3);
	effect->setColor(QColor(255,0,0,255));
	effect->setOffset(1,1);
	ui->label->setGraphicsEffect(effect);

    ui->comboBox->setIconSize(QSize(40, 40));
    profileList = new QVector<Profile>();
    for(unsigned int i = 1; i < profileList->size(); ++i){
        if(profileList->at(i).avatar == 0){
            ui->comboBox->addItem(QIcon(":/avatars/avatar1"), QString(profileList->at(i).name.c_str()));
        }else if(profileList->at(i).avatar == 1){
            ui->comboBox->addItem(QIcon(":/avatars/avatar2"), QString(profileList->at(i).name.c_str()));
        }else if(profileList->at(i).avatar == 2){
            ui->comboBox->addItem(QIcon(":/avatars/avatar3"), QString(profileList->at(i).name.c_str()));
        }else if(profileList->at(i).avatar == 3){
            ui->comboBox->addItem(QIcon(":/avatars/avatar4"), QString(profileList->at(i).name.c_str()));
        }else if(profileList->at(i).avatar == 4){
            ui->comboBox->addItem(QIcon(":/avatars/avatar5"), QString(profileList->at(i).name.c_str()));
        }else if(profileList->at(i).avatar == 5){
            ui->comboBox->addItem(QIcon(":/avatars/avatar6"), QString(profileList->at(i).name.c_str()));
        }
    }
}

DeleteProfile::~DeleteProfile()
{
	delete ui;
}

QVector<Profile>* DeleteProfile::getProfiles(){
    return profileList;
}

void DeleteProfile::on_buttonDelete_clicked()
{
    Profile p;
    p.name = ui->comboBox->itemText(ui->comboBox->currentIndex()).toStdString();
    for(int i = 0; i< profileList->size();i++){
        if(p.name==profileList->at(i).name)
            p.avatar = profileList->at(i).avatar;
    }
    p.type = 0;
    emit  accepted(p);
}

void DeleteProfile::on_buttonCancel_clicked()
{
	emit rejected();
}

void DeleteProfile::update(){
    ui->comboBox->clear();
    for(unsigned int i = 1; i < profileList->size(); ++i){
        if(profileList->at(i).avatar == 0){
            ui->comboBox->addItem(QIcon(":/avatars/avatar1"), QString(profileList->at(i).name.c_str()));
        }else if(profileList->at(i).avatar == 1){
            ui->comboBox->addItem(QIcon(":/avatars/avatar2"), QString(profileList->at(i).name.c_str()));
        }else if(profileList->at(i).avatar == 2){
            ui->comboBox->addItem(QIcon(":/avatars/avatar3"), QString(profileList->at(i).name.c_str()));
        }else if(profileList->at(i).avatar == 3){
            ui->comboBox->addItem(QIcon(":/avatars/avatar4"), QString(profileList->at(i).name.c_str()));
        }else if(profileList->at(i).avatar == 4){
            ui->comboBox->addItem(QIcon(":/avatars/avatar5"), QString(profileList->at(i).name.c_str()));
        }else if(profileList->at(i).avatar == 5){
            ui->comboBox->addItem(QIcon(":/avatars/avatar6"), QString(profileList->at(i).name.c_str()));
        }
    }

    QWidget::update();
}
