#include "RulesOption.h"
#include "ui_RulesOption.h"

RulesOption::RulesOption(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::RulesOption)
{
	ui->setupUi(this);
}

RulesOption::~RulesOption()
{
	delete ui;
}

void RulesOption::on_buttonBack_clicked(){
	emit backOptions();
}
