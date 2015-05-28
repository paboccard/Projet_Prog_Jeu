#include "BoardWidget.h"
#include "ui_Board.h"

BoardWidget::BoardWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Board)
{
	ui->setupUi(this);
}

BoardWidget::~BoardWidget()
{
	delete ui;
}

void BoardWidget::on_buttonHelp_clicked()
{
	emit helped();
}

void BoardWidget::on_buttonStartTravel_clicked()
{
	emit startedTravel();
}

void BoardWidget::on_buttonExit_clicked()
{
	emit exitGame();
}

void BoardWidget::on_buttonSave_clicked()
{
	emit saved();
}
