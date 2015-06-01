#include "NewLocalGame.h"
#include "ui_NewLocalGame.h"
#include <QtGui>
#include <iostream>
#include <QStyledItemDelegate>
#include <QComboBox>

NewLocalGame::NewLocalGame(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::NewLocalGame)
{
    ui->setupUi(this);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(3);
    effect->setColor(QColor(255,0,0,255));
    effect->setOffset(1,1);
    ui->label->setGraphicsEffect(effect);

    int w = ui->tablePlayer->verticalHeader()->width() + 4;
    for (int i = 0; i < ui->tablePlayer->columnCount(); i++)
          w += ui->tablePlayer->columnWidth(i);
    int h = ui->tablePlayer->horizontalHeader()->height() + 4;
    for (int i = 0; i < ui->tablePlayer->rowCount(); i++)
          h += ui->tablePlayer->rowHeight(i);

    // initialize first raw with current profile
    QTableWidgetItem* itemName = new QTableWidgetItem;
    QTableWidgetItem* itemAvatar = new QTableWidgetItem;
	ui->tablePlayer->setItem(0, 2, itemName);
	ui->tablePlayer->setItem(0, 1, itemAvatar);


	//initialize type combobox
	QComboBox *comboBoxType1 = new QComboBox;
	QComboBox *comboBoxType2 = new QComboBox;
	QComboBox *comboBoxType3 = new QComboBox;
	QComboBox *comboBoxType4 = new QComboBox;
	QComboBox *comboBoxType5 = new QComboBox;
	ui->tablePlayer->setCellWidget(0, 0, comboBoxType1);
	ui->tablePlayer->setCellWidget(1, 0, comboBoxType2);
	ui->tablePlayer->setCellWidget(2, 0, comboBoxType3);
	ui->tablePlayer->setCellWidget(3, 0, comboBoxType4);
	ui->tablePlayer->setCellWidget(4, 0, comboBoxType5);

	QVector<QString> typeList;
	typeList.push_back("Humain");
	typeList.push_back("IA niveau 1");
	typeList.push_back("IA niveau 2");
	typeList.push_back("IA niveau 3");

	for(unsigned int i = 0; i < typeList.size(); ++i){
		comboBoxType1->addItem(QIcon(""), typeList.at(i));
		comboBoxType2->addItem(QIcon(""), typeList.at(i));
		comboBoxType3->addItem(QIcon(""), typeList.at(i));
		comboBoxType4->addItem(QIcon(""), typeList.at(i));
		comboBoxType5->addItem(QIcon(""), typeList.at(i));
	}

	//initialize color combobox
	QComboBox *comboBoxColor1 = new QComboBox;
	QComboBox *comboBoxColor2 = new QComboBox;
	QComboBox *comboBoxColor3 = new QComboBox;
	QComboBox *comboBoxColor4 = new QComboBox;
	QComboBox *comboBoxColor5 = new QComboBox;
	ui->tablePlayer->setCellWidget(0, 3, comboBoxColor1);
	ui->tablePlayer->setCellWidget(1, 3, comboBoxColor2);
	ui->tablePlayer->setCellWidget(2, 3, comboBoxColor3);
	ui->tablePlayer->setCellWidget(3, 3, comboBoxColor4);
	ui->tablePlayer->setCellWidget(4, 3, comboBoxColor5);

	comboBoxColor1->setIconSize(QSize(100, 15));
	comboBoxColor2->setIconSize(QSize(100, 15));
	comboBoxColor3->setIconSize(QSize(100, 15));
	comboBoxColor4->setIconSize(QSize(100, 15));
	comboBoxColor5->setIconSize(QSize(100, 15));
	QPixmap colorIcon(100, 15);
	QVector<QColor> colorList;
	colorList.push_back(QColor(255, 255, 255, 255));
	colorList.push_back(QColor(194, 169, 160, 255));
	colorList.push_back(QColor(235, 206, 157, 255));
	colorList.push_back(QColor(254, 121,   5, 255));
	colorList.push_back(QColor(255, 195,  78, 255));
	colorList.push_back(QColor(111, 203, 172, 255));

	for(unsigned int i = 0; i < colorList.size(); ++i){
		colorIcon.fill(colorList.at(i));
		comboBoxColor1->addItem(colorIcon, QString(""));
		comboBoxColor2->addItem(colorIcon, QString(""));
		comboBoxColor3->addItem(colorIcon, QString(""));
		comboBoxColor4->addItem(colorIcon, QString(""));
		comboBoxColor5->addItem(colorIcon, QString(""));
	}

	// first row disable
	Qt::ItemFlags flags = Qt::NoItemFlags;
	itemName->setFlags(flags);
	itemAvatar->setFlags(flags);

    // two row visible at first
    ui->tablePlayer->setRowHidden(2, true);
    ui->tablePlayer->setRowHidden(3, true);
    ui->tablePlayer->setRowHidden(4, true);
}

NewLocalGame::~NewLocalGame()
{
	delete ui;
}

QTableWidgetItem* NewLocalGame::getItemName(){
	return ui->tablePlayer->item(0,2);
}

QTableWidgetItem* NewLocalGame::getItemAvatar(){
	return ui->tablePlayer->item(0,1);
}

void NewLocalGame::on_buttonCancel_clicked()
{
	emit rejected();
}

void NewLocalGame::on_buttonPlay_clicked()
{
	emit accepted(ui->spinNbPlayer->value());
}

void NewLocalGame::on_buttonNewProfil_clicked()
{
	emit newProfil();
}

void NewLocalGame::on_spinNbPlayer_valueChanged(int nb)
{
    if(nb==2){
        ui->tablePlayer->update();
        ui->tablePlayer->setRowHidden(2, true);
        ui->tablePlayer->setRowHidden(3, true);
        ui->tablePlayer->setRowHidden(4, true);
    }else if(nb==3){
        ui->tablePlayer->update();
        ui->tablePlayer->setRowHidden(2, false);
        ui->tablePlayer->setRowHidden(3, true);
        ui->tablePlayer->setRowHidden(4, true);
    }else if(nb==4){
        ui->tablePlayer->update();
        ui->tablePlayer->setRowHidden(2, false);
        ui->tablePlayer->setRowHidden(3, false);
        ui->tablePlayer->setRowHidden(4, true);
    }else if(nb==5){
        ui->tablePlayer->update();
        ui->tablePlayer->setRowHidden(2, false);
        ui->tablePlayer->setRowHidden(3, false);
        ui->tablePlayer->setRowHidden(4, false);
    }
}
