#include "PlayerWidget.h"
#include "ui_PlayerWidget.h"
#include <QDebug>

PlayerWidget::PlayerWidget(Player *p) :
	QWidget(),
	ui(new Ui::PlayerWidget)
{
	ui->setupUi(this);

	ui->horizontalLayout->setAlignment(ui->labelStop, Qt::AlignRight);
	ui->horizontalLayout->setAlignment(ui->labelLine, Qt::AlignRight);

	hand = new HandWidget();
	hand->setMinSize(40);
	hand->setDragAndDrop(false);

	ui->layoutHand->addWidget(hand);
	setPlayer(p);

}

void PlayerWidget::setPlayer(Player *p) {
	player = p;

	ui->labelAvatar->setPixmap(QPixmap(":/avatars/avatar"+QString::number(player->getProfile().avatar + 1)).scaledToHeight(80));
	ui->labelNamePlayer->setText(QString::fromStdString(player->getProfile().name));
	ui->labelLine->setPixmap(QPixmap(":/cards/cartesBack").scaledToHeight(80));
	ui->labelStop->setPixmap(QPixmap(":/cards/cartesBack").scaledToHeight(80));
	hand->setHand(p->getHand());
}

PlayerWidget::~PlayerWidget()
{
	delete ui;
}

void PlayerWidget::resizeEvent(QResizeEvent *e)
{
}

void PlayerWidget::updateHand()
{
	hand->update();
}
