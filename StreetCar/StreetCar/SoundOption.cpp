#include "SoundOption.h"
#include "ui_SoundOption.h"
#include <QtGui>

SoundOption::SoundOption(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::SoundOption)
{
	ui->setupUi(this);
    ui->radioButtonMusic2->setChecked(true);
    ui->radioButtonEffect2->setChecked(true);

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
	emit accepted();
}

void SoundOption::on_buttonCancel_clicked(){
	emit rejected();
}
