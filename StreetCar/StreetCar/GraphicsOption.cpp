#include "GraphicsOption.h"
#include "ui_GraphicsOption.h"
#include <QtGui>

GraphicsOption::GraphicsOption(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::GraphicsOption)
{
	ui->setupUi(this);
	ui->radioButtonFullScreen2->setChecked(true);

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
	emit accepted();
}

void GraphicsOption::on_buttonCancel_clicked(){
	emit rejected();
}

