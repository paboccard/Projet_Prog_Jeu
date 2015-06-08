#include "DescriptionPlayersNetwork.h"
#include "ui_DescriptionPlayersNetwork.h"

DescriptionPlayersNetwork::DescriptionPlayersNetwork(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::DescriptionPlayersNetwork)
{
	ui->setupUi(this);
}

DescriptionPlayersNetwork::~DescriptionPlayersNetwork()
{
	delete ui;
}

void DescriptionPlayersNetwork::newPlayerAdded(std::vector<Profile> p)
{
	ui->tableWidget->clearContents();
}

void DescriptionPlayersNetwork::on_buttonPlay_clicked()
{
	emit accepted();
}

void DescriptionPlayersNetwork::on_buttonExit_clicked()
{
	emit rejected();
}
