#include "CreditsOption.h"
#include "ui_CreditsOption.h"
#include <QtGui>

CreditsOption::CreditsOption(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CreditsOption)
{
	ui->setupUi(this);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(3);
    effect->setColor(QColor(255,0,0,255));
    effect->setOffset(1,1);
    ui->label->setGraphicsEffect(effect);
}

CreditsOption::~CreditsOption()
{
	delete ui;
}

void CreditsOption::on_buttonBack_clicked(){
	emit backOptions();
}
