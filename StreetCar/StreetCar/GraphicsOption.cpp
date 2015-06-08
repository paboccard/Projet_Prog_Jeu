#include "GraphicsOption.h"
#include "ui_GraphicsOption.h"
#include <QGraphicsDropShadowEffect>
#include <QtGui>
#include <iostream>
#include <QDesktopWidget>

using namespace std;
GraphicsOption::GraphicsOption(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::GraphicsOption)
{
	ui->setupUi(this);
	ui->radioButtonFullScreen2->setChecked(true);

    //resolution screen user
	w = qApp->desktop()->width();
	h = qApp->desktop()->height();

    ui->comboBoxResolution->addItem(QIcon(""), QString(QString::number(w)+" x "+QString::number(h)));
    ui->comboBoxResolution->setCurrentIndex(0);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(3);
    effect->setColor(QColor(255,0,0,255));
    effect->setOffset(1,1);
    ui->label->setGraphicsEffect(effect);
}

GraphicsOption::~GraphicsOption()
{
	delete ui;
}

void GraphicsOption::on_buttonAccept_clicked(){
    if(ui->radioButtonFullScreen1->isChecked()==true){
        fullScreen = true;
    }else{
        fullScreen = false;
    }
    emit accepted(fullScreen, w, h);
}

void GraphicsOption::on_buttonCancel_clicked(){
	emit rejected();
}


void GraphicsOption::on_comboBoxResolution_currentIndexChanged(int index)
{

}
