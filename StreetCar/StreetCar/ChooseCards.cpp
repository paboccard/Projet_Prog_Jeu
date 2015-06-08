#include "ChooseCards.h"
#include "ui_ChooseCards.h"
#include <iostream>
#include <QDebug>

using namespace std;

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

	cardsStopList = new QVector<QString>();
	cardsStopList->push_back("border-image: url(:/cards/carteArrets7)");
	cardsStopList->push_back("border-image: url(:/cards/carteArrets8)");
	cardsStopList->push_back("border-image: url(:/cards/carteArrets9)");
	cardsStopList->push_back("border-image: url(:/cards/carteArrets10)");
	cardsStopList->push_back("border-image: url(:/cards/carteArrets11)");
	cardsStopList->push_back("border-image: url(:/cards/carteArrets12)");

	goal = new QVector<Goal>();
}

ChooseCards::~ChooseCards()
{
	delete ui;
}

void ChooseCards::update(){
	ui->groupBoxLine->setDisabled(false);
	ui->groupBoxStops->setDisabled(false);
	ui->buttonCardLine1->setStyleSheet("QPushButton {border-image: url(:/cards/cartesBack) }");
	ui->buttonCardLine2->setStyleSheet("QPushButton {border-image: url(:/cards/cartesBack) }");
	ui->buttonCardLine3->setStyleSheet("QPushButton {border-image: url(:/cards/cartesBack) }");
	ui->buttonCardLine4->setStyleSheet("QPushButton {border-image: url(:/cards/cartesBack) }");
	ui->buttonCardLine5->setStyleSheet("QPushButton {border-image: url(:/cards/cartesBack) }");
	ui->buttonCardLine6->setStyleSheet("QPushButton {border-image: url(:/cards/cartesBack) }");
	ui->buttonCardStops1->setStyleSheet("QPushButton {border-image: url(:/cards/cartesBack) }");
	ui->buttonCardStops2->setStyleSheet("QPushButton {border-image: url(:/cards/cartesBack) }");
	ui->buttonCardStops3->setStyleSheet("QPushButton {border-image: url(:/cards/cartesBack) }");
	ui->buttonCardStops4->setStyleSheet("QPushButton {border-image: url(:/cards/cartesBack) }");
	ui->buttonCardStops5->setStyleSheet("QPushButton {border-image: url(:/cards/cartesBack) }");
	ui->buttonCardStops6->setStyleSheet("QPushButton {border-image: url(:/cards/cartesBack) }");
}

QVector<Goal> *ChooseCards::getGoal(){
	return goal;
}

void ChooseCards::on_buttonCardLine1_clicked()
{
	for(int i = 0; i< cardsLineList->size(); i++){
		if(goal->at(0).goalPlayer.line==i){
			ui->buttonCardLine1->setStyleSheet(cardsLineList->at(i));
		}
	}
    ui->buttonCardLine1->show();
	ui->groupBoxLine->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardLine2_clicked()
{
	for(int i = 0; i< cardsLineList->size(); i++){
		if(goal->at(0).goalPlayer.line==i){
			ui->buttonCardLine2->setStyleSheet(cardsLineList->at(i));
		}
	}
    ui->buttonCardLine2->show();
	ui->groupBoxLine->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardLine3_clicked()
{
	for(int i = 0; i< cardsLineList->size(); i++){
		if(goal->at(0).goalPlayer.line==i){
			ui->buttonCardLine3->setStyleSheet(cardsLineList->at(i));
		}
	}
	ui->buttonCardLine3->show();
	ui->groupBoxLine->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardLine4_clicked()
{
	for(int i = 0; i< cardsLineList->size(); i++){
		if(goal->at(0).goalPlayer.line==i){
			ui->buttonCardLine4->setStyleSheet(cardsLineList->at(i));
		}
	}
	ui->buttonCardLine4->show();
	ui->groupBoxLine->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardLine5_clicked()
{
	for(int i = 0; i< cardsLineList->size(); i++){
		if(goal->at(0).goalPlayer.line==i){
			ui->buttonCardLine5->setStyleSheet(cardsLineList->at(i));
		}
	}
	ui->buttonCardLine5->show();
	ui->groupBoxLine->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardLine6_clicked()
{
	for(int i = 0; i< cardsLineList->size(); i++){
		if(goal->at(0).goalPlayer.line==i){
			ui->buttonCardLine6->setStyleSheet(cardsLineList->at(i));
		}
	}
	ui->buttonCardLine6->show();
	ui->groupBoxLine->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardStops1_clicked()
{
	for(int i = 0; i< cardsStopList->size(); i++){
		if(goal->at(0).goalPlayer.stop.numCard==i){
			ui->buttonCardStops1->setStyleSheet(cardsStopList->at(i));
		}
	}
	ui->buttonCardStops1->show();
	ui->groupBoxStops->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardStops2_clicked()
{
	for(int i = 0; i< cardsStopList->size(); i++){
		if(goal->at(0).goalPlayer.stop.numCard==i){
			ui->buttonCardStops2->setStyleSheet(cardsStopList->at(i));

		}
	}
	ui->buttonCardStops2->show();
	ui->groupBoxStops->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardStops3_clicked()
{
	for(int i = 0; i< cardsStopList->size(); i++){
		if(goal->at(0).goalPlayer.stop.numCard==i){
			ui->buttonCardStops3->setStyleSheet(cardsStopList->at(i));
		}
	}
	ui->buttonCardStops3->show();
	ui->groupBoxStops->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardStops4_clicked()
{
	for(int i = 0; i< cardsStopList->size(); i++){
		if(goal->at(0).goalPlayer.stop.numCard==i){
			ui->buttonCardStops4->setStyleSheet(cardsStopList->at(i));
		}
	}
	ui->buttonCardStops4->show();
	ui->groupBoxStops->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardStops5_clicked()
{
	for(int i = 0; i< cardsStopList->size(); i++){
		if(goal->at(0).goalPlayer.stop.numCard==i){
			ui->buttonCardStops5->setStyleSheet(cardsStopList->at(i));
		}
	}
	ui->buttonCardStops5->show();
	ui->groupBoxStops->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonCardStops6_clicked()
{
	for(int i = 0; i< cardsStopList->size(); i++){
		if(goal->at(0).goalPlayer.stop.numCard==i){
			ui->buttonCardStops6->setStyleSheet(cardsStopList->at(i));
		}
	}
	ui->buttonCardStops6->show();
	ui->groupBoxStops->setDisabled(true);
	emit accepted();
}

void ChooseCards::on_buttonValidate_clicked()
{
	emit validated();
}
