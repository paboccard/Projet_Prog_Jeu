#include "LoadSaveGame.h"
#include "ui_LoadSaveGame.h"
#include <QGraphicsDropShadowEffect>
#include <QtGui>

LoadSaveGame::LoadSaveGame(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::LoadSaveGame)
{
	ui->setupUi(this);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(3);
    effect->setColor(QColor(255,0,0,255));
    effect->setOffset(1,1);
    ui->label->setGraphicsEffect(effect);
}

LoadSaveGame::~LoadSaveGame()
{
	delete ui;
}

void LoadSaveGame::on_buttonAccept_clicked(){
	emit accepted();
}

void LoadSaveGame::on_buttonCancel_clicked(){
	emit rejected();
}

void LoadSaveGame::on_buttonDelete_clicked()
{
	emit deleted();
}

void LoadSaveGame::on_buttonSave_clicked()
{
	emit saved();
}
