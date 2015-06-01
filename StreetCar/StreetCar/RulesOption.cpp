#include "RulesOption.h"
#include "ui_RulesOption.h"
#include <QtGui>

RulesOption::RulesOption(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::RulesOption)
{
	ui->setupUi(this);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(3);
    effect->setColor(QColor(255,0,0,255));
    effect->setOffset(1,1);
    ui->label->setGraphicsEffect(effect);
}

RulesOption::~RulesOption()
{
	delete ui;
}

void RulesOption::on_buttonBack_clicked(){
	emit backOptions();
}
