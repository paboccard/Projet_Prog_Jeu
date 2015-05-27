#include "SoundOption.h"
#include "ui_SoundOption.h"

SoundOption::SoundOption(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::SoundOption)
{
	ui->setupUi(this);
}

SoundOption::~SoundOption()
{
	delete ui;
}

void SoundOption::on_buttonAccept_clicked(){
	emit accepted();
}

void SoundOption::on_buttonCancel_clicked(){
	emit rejected();
}
