#include "SoundOption.h"
#include "ui_SoundOption.h"
#include <QGraphicsDropShadowEffect>
#include <QtGui>
#include <iostream>
#include <QApplication>
#include <QUrl>

using namespace std;

SoundOption::SoundOption(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::SoundOption)
{
	ui->setupUi(this);
	ui->radioButtonMusic1->setChecked(true);
	ui->radioButtonEffect1->setChecked(true);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(3);
    effect->setColor(QColor(255,0,0,255));
    effect->setOffset(1,1);
    ui->label->setGraphicsEffect(effect);
}

SoundOption::~SoundOption()
{
	delete ui;
}

void SoundOption::on_buttonAccept_clicked(){
	if(ui->radioButtonMusic1->isChecked()){
		musicOn = true;
	}else{
		musicOn = false;
	}
	emit accepted(musicOn);
}

void SoundOption::on_buttonCancel_clicked(){
	emit rejected();
}
