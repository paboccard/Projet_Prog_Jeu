#include "OptionsWindow.h"
#include "ui_OptionsWindow.h"

OptionsWindow::OptionsWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::OptionsWindow)
{
	ui->setupUi(this);
}

OptionsWindow::~OptionsWindow()
{
	delete ui;
}

void OptionsWindow::on_buttonSound_clicked(){
	emit soundOption();
}

void OptionsWindow::on_buttonServer_clicked(){
	emit serverOption();
}

void OptionsWindow::on_buttonGraphics_clicked(){
	emit graphicsOption();
}

void OptionsWindow::on_buttonInstructions_clicked(){
	emit instructionsOption();
}

void OptionsWindow::on_buttonCredits_clicked(){
	emit creditsOption();
}

void OptionsWindow::on_buttonBack_clicked(){
	emit backMenu();
}
