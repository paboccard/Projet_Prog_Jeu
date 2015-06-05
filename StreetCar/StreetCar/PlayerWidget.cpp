#include "PlayerWidget.h"
#include "ui_PlayerWidget.h"

PlayerWidget::PlayerWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::PlayerWidget)
{
	ui->setupUi(this);

	hand = new HandWidget();
	ui->layoutHand->addWidget(hand);
}

PlayerWidget::PlayerWidget(Player *p)
{
	player = p;
	ui->labelNamePlayer->setText(QString::fromStdString(player->getProfile().name));
	hand->setHand(p->getHand());
}

PlayerWidget::~PlayerWidget()
{
	delete ui;
}
