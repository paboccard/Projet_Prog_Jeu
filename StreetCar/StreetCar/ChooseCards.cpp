#include "ChooseCards.h"
#include "ui_ChooseCards.h"
#include <iostream>

ChooseCards::ChooseCards(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ChooseCards)
{
	ui->setupUi(this);
	players = QVector<Player*>();


}

ChooseCards::~ChooseCards()
{
	delete ui;
}

void ChooseCards::update(){
	for(int i=0; i< players.size();i++){
		std::cout << i << " " << players.at(i)->getLine()<<std::endl;
		std::cout << players.at(i)->getProfile().name<<std::endl;
	}
}

QVector<Player*> ChooseCards::getPlayers(){
	return players;
}

void ChooseCards::on_buttonCardLine1_clicked()
{
	ui->buttonCardLine1->setStyleSheet("border-image: url(:/cards/carteArrets1)");
    ui->buttonCardLine1->show();
	ui->groupBoxLine->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardLine2_clicked()
{
	ui->buttonCardLine2->setStyleSheet("border-image: url(:/cards/carteArrets2)");
    ui->buttonCardLine2->show();
	ui->groupBoxLine->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardLine3_clicked()
{
	ui->buttonCardLine3->setStyleSheet("border-image: url(:/cards/carteArrets3)");
	ui->buttonCardLine3->show();
	ui->groupBoxLine->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardLine4_clicked()
{
	ui->buttonCardLine4->setStyleSheet("border-image: url(:/cards/carteArrets4)");
	ui->buttonCardLine4->show();
	ui->groupBoxLine->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardLine5_clicked()
{
	ui->buttonCardLine5->setStyleSheet("border-image: url(:/cards/carteArrets5)");
	ui->buttonCardLine5->show();
	ui->groupBoxLine->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardLine6_clicked()
{
	ui->buttonCardLine6->setStyleSheet("border-image: url(:/cards/carteArrets6)");
	ui->buttonCardLine6->show();
	ui->groupBoxLine->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardStops1_clicked()
{
	ui->buttonCardStops1->setStyleSheet("border-image: url(:/cards/carteArrets7)");
	ui->buttonCardStops1->show();
	ui->groupBoxStops->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardStops2_clicked()
{
	ui->buttonCardStops2->setStyleSheet("border-image: url(:/cards/carteArrets8)");
	ui->buttonCardStops2->show();
	ui->groupBoxStops->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardStops3_clicked()
{
	ui->buttonCardStops3->setStyleSheet("border-image: url(:/cards/carteArrets9)");
	ui->buttonCardStops3->show();
	ui->groupBoxStops->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardStops4_clicked()
{
	ui->buttonCardStops4->setStyleSheet("border-image: url(:/cards/carteArrets10)");
	ui->buttonCardStops4->show();
	ui->groupBoxStops->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardStops5_clicked()
{
	ui->buttonCardStops5->setStyleSheet("border-image: url(:/cards/carteArrets11)");
	ui->buttonCardStops5->show();
	ui->groupBoxStops->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardStops6_clicked()
{
	ui->buttonCardStops6->setStyleSheet("border-image: url(:/cards/carteArrets12)");
	ui->buttonCardStops6->show();
	ui->groupBoxStops->setDisabled(true);
	emit accepted();
}
