#include "DescriptionPlayersNetwork.h"
#include "ui_DescriptionPlayersNetwork.h"
#include <QGraphicsDropShadowEffect>
#include <QtGui>
#include <QDebug>

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

void DescriptionPlayersNetwork::addPlayer(Profile p)
{
	qDebug() << "player add to description player network";
	ui->tablePlayer->insertRow(ui->tablePlayer->rowCount());

	ui->tablePlayer->setItem(ui->tablePlayer->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(p.name)));
	ui->tablePlayer->setItem(ui->tablePlayer->rowCount() - 1, 1, new QTableWidgetItem(QIcon(QString(":/avatars/avatar" + QString::number(p.avatar+1))), QString("")));

}

void DescriptionPlayersNetwork::setGameName(QString s)
{
	ui->label->setText(s);
}

void DescriptionPlayersNetwork::show(bool host)
{
	ui->buttonPlay->setEnabled(host);
	QWidget::show();
}

void DescriptionPlayersNetwork::on_buttonPlay_clicked()
{
	emit accepted();
}

void DescriptionPlayersNetwork::on_buttonExit_clicked()
{
	emit rejected();
}
