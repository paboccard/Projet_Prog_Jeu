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
