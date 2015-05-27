#include "SoundOptionWindow.h"
#include "ui_SoundOptionWindow.h"

SoundOptionWindow::SoundOptionWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::SoundOptionWindow)
{
	ui->setupUi(this);
}

SoundOptionWindow::~SoundOptionWindow()
{
	delete ui;
}
