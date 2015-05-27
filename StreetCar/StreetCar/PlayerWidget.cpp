#include "PlayerWidget.h"
#include "ui_PlayerWidget.h"

PlayerWidget::PlayerWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::PlayerWidget)
{
	ui->setupUi(this);
}

PlayerWidget::~PlayerWidget()
{
	delete ui;
}
