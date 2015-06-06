#include "PlayerWidget.h"
#include "ui_PlayerWidget.h"
#include <QDebug>

PlayerWidget::PlayerWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::PlayerWidget)
{
	ui->setupUi(this);
	ui->horizontalLayout->setAlignment(ui->labelStop, Qt::AlignRight);
	ui->horizontalLayout->setAlignment(ui->labelLine, Qt::AlignRight);
	hand = new HandWidget();
	hand->setMinSize(40);
	hand->setDragAndDrop(false);
	ui->layoutHand->addWidget(hand);
}

PlayerWidget::PlayerWidget(Player *p) :
	   QWidget(),
	   ui(new Ui::PlayerWidget)
{
	ui->setupUi(this);
	hand = new HandWidget();
	hand->setMinSize(40);
	hand->setDragAndDrop(false);
	ui->layoutHand->addWidget(hand);

	player = p;
	qDebug() << "set name player";
	qDebug() << QString::fromStdString(player->getProfile().name);
	ui->labelNamePlayer->setText(QString::fromStdString(player->getProfile().name));
	hand->setHand(p->getHand());
}

PlayerWidget::~PlayerWidget()
{
	delete ui;
}
