#include "SoundOption.h"
#include "ui_SoundOption.h"
#include <QGraphicsDropShadowEffect>
#include <QtGui>
#include <iostream>
#include <QApplication>
#include <QUrl>

using namespace std;

SoundOption::SoundOption(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::SoundOption)
{
	ui->setupUi(this);
    ui->radioButtonMusic2->setChecked(true);
    ui->radioButtonEffect2->setChecked(true);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(3);
    effect->setColor(QColor(255,0,0,255));
    effect->setOffset(1,1);
    ui->label->setGraphicsEffect(effect);

    /*const QUrl url = QUrl( QLatin1String("file:///somepath/somefile") );
        MediaSource src( url );
        MediaObject obj;
        obj.setCurrentSource( src );
        VideoWidget video;
        video.show();
        AudioOutput audio( VideoCategory );
        Phonon::createPath( &obj, &video );
        Phonon::createPath( &obj, &audio );
        obj.play();*/
}

SoundOption::~SoundOption()
{
	delete ui;
}

void SoundOption::on_buttonAccept_clicked(){
    if(ui->radioButtonMusic1->isChecked()){

        //musique->play();

    }
	emit accepted();
}

void SoundOption::on_buttonCancel_clicked(){
	emit rejected();
}
