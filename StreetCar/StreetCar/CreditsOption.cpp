#include "CreditsOption.h"
#include "ui_CreditsOption.h"

CreditsOption::CreditsOption(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CreditsOption)
{
	ui->setupUi(this);
}

CreditsOption::~CreditsOption()
{
	delete ui;
}

void CreditsOption::on_buttonBack_clicked(){
	emit backOptions();
}
