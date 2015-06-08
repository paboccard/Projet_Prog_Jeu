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

	ui->comboServer->addItem("127.0.0.1");

	ui->buttonRefresh->setEnabled(false);
	ui->buttonChoose->setEnabled(false);
	ui->buttonCreate->setEnabled(false);
	ui->tableGame->setEnabled(false);


}

NewNetworkGame::~NewNetworkGame()
{
	delete ui;
}

QString NewNetworkGame::getIpServer()
{
	return ui->comboServer->currentText();
}

void NewNetworkGame::setServers(std::vector<GameNetwork> v)
{
	for (unsigned int i = 0; i < v.size(); i ++){
		//ui->tableGame->insertRow();

		ui->tableGame->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(v[i].name)));
		ui->tableGame->setItem(i, 1, new QTableWidgetItem(QString::number(v[i].nbrPlayers)));
	}
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

	//emit created();
}

void NewNetworkGame::on_buttonChoose_clicked()
{
	emit accepted();
}

void NewNetworkGame::on_tableGame_itemSelectionChanged()
{
	if (ui->tableGame->currentRow() == -1)
		ui->buttonChoose->setEnabled(false);
	else
		ui->buttonChoose->setEnabled(true);
}

void NewNetworkGame::connectedTotheServer()
{
	ui->buttonRefresh->setEnabled(true);
	ui->tableGame->setEnabled(true);
	ui->buttonCreate->setEnabled(true);
}
