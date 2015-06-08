#include "ChooseCards.h"
#include "ui_ChooseCards.h"
#include <iostream>
#include <QDebug>

ChooseCards::ChooseCards(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ChooseCards)
{
	ui->setupUi(this);

	cardsLineList = new QVector<QString>();
	cardsLineList->push_back("border-image: url(:/cards/carteArrets1)");
	cardsLineList->push_back("border-image: url(:/cards/carteArrets2)");
	cardsLineList->push_back("border-image: url(:/cards/carteArrets3)");
	cardsLineList->push_back("border-image: url(:/cards/carteArrets4)");
	cardsLineList->push_back("border-image: url(:/cards/carteArrets5)");
	cardsLineList->push_back("border-image: url(:/cards/carteArrets6)");

	goal = new Goal();
}

ChooseCards::~ChooseCards()
{
	delete ui;
}

void ChooseCards::update(){

}

Goal *ChooseCards::getGoal(){
	return goal;
}

void ChooseCards::on_buttonCardLine1_clicked()
{
	for(int i=0; i< cardsLineList->size();i++){
		if(goal->goalPlayer.line == i){
			cout << goal->goalPlayer.line<<endl;
			cout << i<<endl;
			ui->buttonCardLine1->setStyleSheet(cardsLineList->at(i));
		}
	}
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
