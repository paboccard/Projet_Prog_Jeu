#include "TileWidget.h"
#include "ui_TileWidget.h"

TileWidget::TileWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::TileWidget)
{
	ui->setupUi(this);
}

TileWidget::~TileWidget()
{
	delete ui;
}
