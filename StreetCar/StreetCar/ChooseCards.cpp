#include "ChooseCards.h"
#include "ui_ChooseCards.h"

ChooseCards::ChooseCards(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ChooseCards)
{
	ui->setupUi(this);
}

ChooseCards::~ChooseCards()
{
	delete ui;
}

void ChooseCards::on_buttonCardLine1_clicked()
{
	ui->buttonCardLine1->setStyleSheet("border-image: url(:/cards/carteArrets1)");

    ui->buttonCardLine1->show();
    emit accepted();
}

void ChooseCards::on_buttonCardLine2_clicked()
{
	ui->buttonCardLine2->setStyleSheet("border-image: url(:/cards/carteArrets2)");

    ui->buttonCardLine2->show();
    emit accepted();
}

void ChooseCards::on_buttonCardLine3_clicked()
{
	ui->buttonCardLine3->setStyleSheet("border-image: url(:/cards/carteArrets3)");
	ui->buttonCardLine3->show();
	emit accepted();
}

void ChooseCards::on_buttonCardLine4_clicked()
{
	ui->buttonCardLine4->setStyleSheet("border-image: url(:/cards/carteArrets4)");
	ui->buttonCardLine4->show();
	emit accepted();
}

void ChooseCards::on_buttonCardLine5_clicked()
{
	ui->buttonCardLine5->setStyleSheet("border-image: url(:/cards/carteArrets5)");
	ui->buttonCardLine5->show();
	emit accepted();
}

void ChooseCards::on_buttonCardLine6_clicked()
{
	ui->buttonCardLine6->setStyleSheet("border-image: url(:/cards/carteArrets6)");
	ui->buttonCardLine6->show();
	emit accepted();
}

void ChooseCards::on_buttonCardLine7_clicked()
{
	ui->buttonCardLine7->setStyleSheet("border-image: url(:/cards/carteArrets7)");
	ui->buttonCardLine7->show();
	emit accepted();
}

void ChooseCards::on_buttonCardLine8_clicked()
{
	ui->buttonCardLine8->setStyleSheet("border-image: url(:/cards/carteArrets8)");
	ui->buttonCardLine8->show();
	emit accepted();
}

void ChooseCards::on_buttonCardLine9_clicked()
{
	ui->buttonCardLine9->setStyleSheet("border-image: url(:/cards/carteArrets9)");
	ui->buttonCardLine9->show();
	emit accepted();
}

void ChooseCards::on_buttonCardLine10_clicked()
{
	ui->buttonCardLine10->setStyleSheet("border-image: url(:/cards/carteArrets10)");
	ui->buttonCardLine10->show();
	emit accepted();
}

void ChooseCards::on_buttonCardLine11_clicked()
{
	ui->buttonCardLine11->setStyleSheet("border-image: url(:/cards/carteArrets11)");
	ui->buttonCardLine11->show();
	emit accepted();
}

void ChooseCards::on_buttonCardLine12_clicked()
{
	ui->buttonCardLine12->setStyleSheet("border-image: url(:/cards/carteArrets12)");
	ui->buttonCardLine12->show();
	emit accepted();
}

void ChooseCards::on_groupBox_clicked()
{

}
