#include "DeleteProfile.h"
#include "ui_DeleteProfile.h"
#include <QtGui>

DeleteProfile::DeleteProfile(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::DeleteProfile)
{
	ui->setupUi(this);

	QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
	effect->setBlurRadius(3);
	effect->setColor(QColor(255,0,0,255));
	effect->setOffset(1,1);
	ui->label->setGraphicsEffect(effect);
}

DeleteProfile::~DeleteProfile()
{
	delete ui;
}

void DeleteProfile::on_buttonDelete_clicked()
{
	emit  accepted(Profile());
}

void DeleteProfile::on_buttonCancel_clicked()
{
	emit rejected();
}
