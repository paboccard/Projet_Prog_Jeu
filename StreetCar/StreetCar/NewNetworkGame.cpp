#include "NewNetworkGame.h"
#include "ui_NewNetworkGame.h"
#include <QGraphicsDropShadowEffect>
#include <QtGui>
#include <iostream>

NewNetworkGame::NewNetworkGame(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::NewNetworkGame)
{
	ui->setupUi(this);

	QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
	effect->setBlurRadius(3);
	effect->setColor(QColor(255,0,0,255));
	effect->setOffset(1,1);
	ui->label->setGraphicsEffect(effect);

	//size column row table width height
	int w = ui->tableGame->columnWidth(1);
	w = w +500;

}

NewNetworkGame::~NewNetworkGame()
{
	delete ui;
}

void NewNetworkGame::on_buttonConnect_clicked()
{
	emit connected();
}

void NewNetworkGame::on_buttonRefresh_clicked()
{
	emit refreshed();
}

void NewNetworkGame::on_buttonCancel_clicked()
{
	emit rejected();
}

void NewNetworkGame::on_buttonCreate_clicked()
{
	emit created();
}

void NewNetworkGame::on_buttonNext_clicked()
{
	emit accepted();
}
