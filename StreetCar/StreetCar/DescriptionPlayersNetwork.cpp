#include "DescriptionPlayersNetwork.h"
#include "ui_DescriptionPlayersNetwork.h"
#include <QGraphicsDropShadowEffect>
#include <QtGui>

DescriptionPlayersNetwork::DescriptionPlayersNetwork(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::DescriptionPlayersNetwork)
{
	ui->setupUi(this);

	QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
	effect->setBlurRadius(3);
	effect->setColor(QColor(255,0,0,255));
	effect->setOffset(1,1);
	ui->label->setGraphicsEffect(effect);
}

DescriptionPlayersNetwork::~DescriptionPlayersNetwork()
{
	delete ui;
}

void DescriptionPlayersNetwork::on_buttonPlay_clicked()
{
	emit accepted();
}

void DescriptionPlayersNetwork::on_buttonExit_clicked()
{
	emit rejected();
}
