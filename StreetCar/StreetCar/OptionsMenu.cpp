#include "OptionsMenu.h"
#include "ui_OptionsMenu.h"

OptionsMenu::OptionsMenu(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::OptionsMenu)
{
	ui->setupUi(this);
}

OptionsMenu::~OptionsMenu()
{
	delete ui;
}

void OptionsMenu::on_buttonSound_clicked(){
	emit soundOption();
}

void OptionsMenu::on_buttonServer_clicked(){
	emit serverOption();
}

void OptionsMenu::on_buttonGraphics_clicked(){
	emit graphicsOption();
}

void OptionsMenu::on_buttonRules_clicked(){
	emit rulesOption();
}

void OptionsMenu::on_buttonCredits_clicked(){
	emit creditsOption();
}

void OptionsMenu::on_buttonBack_clicked(){
	emit backMenu();
}
