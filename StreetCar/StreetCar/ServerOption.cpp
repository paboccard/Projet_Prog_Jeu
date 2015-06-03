#include "ServerOption.h"
#include "ui_ServerOption.h"
#include <QGraphicsDropShadowEffect>
#include <QtGui>

ServerOption::ServerOption(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ServerOption)
{
	ui->setupUi(this);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(3);
    effect->setColor(QColor(255,0,0,255));
    effect->setOffset(1,1);
    ui->label->setGraphicsEffect(effect);
}

ServerOption::~ServerOption()
{
	delete ui;
}

void ServerOption::on_buttonAccept_clicked(){
	emit accepted();
}

void ServerOption::on_buttonCancel_clicked(){
	emit rejected();
}
