#include "CreateNetworkGame.h"
#include "ui_CreateNetworkGame.h"
#include <QtGui>

CreateNetworkGame::CreateNetworkGame(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CreateNetworkGame)
{
	ui->setupUi(this);

	QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
	effect->setBlurRadius(3);
	effect->setColor(QColor(255,0,0,255));
	effect->setOffset(1,1);
	ui->label->setGraphicsEffect(effect);

    ui->radioButtonPublic->setChecked(true);
}

CreateNetworkGame::~CreateNetworkGame()
{
	delete ui;
}

void CreateNetworkGame::on_buttonCreate_clicked()
{
	emit accepted();
}

void CreateNetworkGame::on_buttonCancel_clicked()
{
	emit rejected();
}
