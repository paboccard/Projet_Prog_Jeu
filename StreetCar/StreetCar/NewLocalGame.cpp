#include "NewLocalGame.h"
#include "ui_NewLocalGame.h"
#include <QGraphicsDropShadowEffect>
#include <QtGui>
#include <iostream>

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

    //size column row table width height
	int w = ui->tablePlayer->verticalHeader()->width() + 4;
    for (int i = 0; i < ui->tablePlayer->columnCount(); i++)
		  w += ui->tablePlayer->columnWidth(i);
	int h = ui->tablePlayer->horizontalHeader()->height() + 4;
	for (int i = 0; i < ui->tablePlayer->rowCount(); i++){
		  h += ui->tablePlayer->rowHeight(i);
		ui->tablePlayer->setRowHeight(i,40);
	}

    //flags for no action
    flags = Qt::NoItemFlags;

    // initialize first raw with current profile
    itemName = new QTableWidgetItem;
    itemAvatar = new QTableWidgetItem;
	ui->tablePlayer->setItem(0, 2, itemName);
	ui->tablePlayer->setItem(0, 1, itemAvatar);


	//initialize avatar combobox
	comboBoxAvatar1 = new QComboBox;
	comboBoxAvatar2 = new QComboBox;
	comboBoxAvatar3 = new QComboBox;
	comboBoxAvatar4 = new QComboBox;
	comboBoxAvatar5 = new QComboBox;
	ui->tablePlayer->setCellWidget(0, 1, comboBoxAvatar1);
	ui->tablePlayer->setCellWidget(1, 1, comboBoxAvatar2);
	ui->tablePlayer->setCellWidget(2, 1, comboBoxAvatar3);
	ui->tablePlayer->setCellWidget(3, 1, comboBoxAvatar4);
	ui->tablePlayer->setCellWidget(4, 1, comboBoxAvatar5);

	comboBoxAvatar1->setIconSize(QSize(40, 40));
	comboBoxAvatar2->setIconSize(QSize(40, 40));
	comboBoxAvatar3->setIconSize(QSize(40, 40));
	comboBoxAvatar4->setIconSize(QSize(40, 40));
	comboBoxAvatar5->setIconSize(QSize(40, 40));

	QVector<QIcon> avatarList;
	avatarList.push_back(QIcon(":/avatars/avatar1"));
	avatarList.push_back(QIcon(":/avatars/avatar2"));
	avatarList.push_back(QIcon(":/avatars/avatar3"));
	avatarList.push_back(QIcon(":/avatars/avatar4"));
	avatarList.push_back(QIcon(":/avatars/avatar5"));
	avatarList.push_back(QIcon(":/avatars/avatar6"));

	for(unsigned int i = 0; i < avatarList.size(); ++i){
		comboBoxAvatar1->addItem(avatarList.at(i), QString(""));
		comboBoxAvatar2->addItem(avatarList.at(i), QString(""));
		comboBoxAvatar3->addItem(avatarList.at(i), QString(""));
		comboBoxAvatar4->addItem(avatarList.at(i), QString(""));
		comboBoxAvatar5->addItem(avatarList.at(i), QString(""));
	}

	//initialize name combobox
	comboBoxName1 = new QComboBox;
	comboBoxName2 = new QComboBox;
	comboBoxName3 = new QComboBox;
	comboBoxName4 = new QComboBox;
	comboBoxName5 = new QComboBox;
	ui->tablePlayer->setCellWidget(0, 2, comboBoxName1);
	ui->tablePlayer->setCellWidget(1, 2, comboBoxName2);
	ui->tablePlayer->setCellWidget(2, 2, comboBoxName3);
	ui->tablePlayer->setCellWidget(3, 2, comboBoxName4);
	ui->tablePlayer->setCellWidget(4, 2, comboBoxName5);

	nameList = new QVector<QString>();

	std::cout << nameList->size();

	for(unsigned int i = 0; i < nameList->size(); ++i){
		comboBoxType1->addItem(QIcon(""), nameList->at(i));
		comboBoxType2->addItem(QIcon(""), nameList->at(i));
		comboBoxType3->addItem(QIcon(""), nameList->at(i));
		comboBoxType4->addItem(QIcon(""), nameList->at(i));
		comboBoxType5->addItem(QIcon(""), nameList->at(i));
	}

	//initialize type combobox
    comboBoxType1 = new QComboBox;
    comboBoxType2 = new QComboBox;
    comboBoxType3 = new QComboBox;
    comboBoxType4 = new QComboBox;
    comboBoxType5 = new QComboBox;
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

	//signal gestion type combobox
	connect(comboBoxType1, SIGNAL(currentIndexChanged(int)), this, SLOT(changeType(int)));

	//initialize color combobox
    comboBoxColor1 = new QComboBox;
    comboBoxColor2 = new QComboBox;
    comboBoxColor3 = new QComboBox;
    comboBoxColor4 = new QComboBox;
    comboBoxColor5 = new QComboBox;
	ui->tablePlayer->setCellWidget(0, 3, comboBoxColor1);
	ui->tablePlayer->setCellWidget(1, 3, comboBoxColor2);
	ui->tablePlayer->setCellWidget(2, 3, comboBoxColor3);
	ui->tablePlayer->setCellWidget(3, 3, comboBoxColor4);
	ui->tablePlayer->setCellWidget(4, 3, comboBoxColor5);

	comboBoxColor1->setIconSize(QSize(70, 30));
	comboBoxColor2->setIconSize(QSize(70, 30));
	comboBoxColor3->setIconSize(QSize(70, 30));
	comboBoxColor4->setIconSize(QSize(70, 30));
	comboBoxColor5->setIconSize(QSize(70, 30));
	QPixmap colorIcon(70, 25);
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

    // two row visible at first
    ui->tablePlayer->setRowHidden(2, true);
    ui->tablePlayer->setRowHidden(3, true);
    ui->tablePlayer->setRowHidden(4, true);

	//first row humain default
	itemName->setFlags(flags);
	itemAvatar->setFlags(flags);
}

NewLocalGame::~NewLocalGame()
{
	delete ui;
}

void NewLocalGame::changeType(int index) {
	if(index==0){ //humain
		ui->tablePlayer->update();
		itemName->setFlags(flags);
		itemAvatar->setFlags(flags);
	}else{
		ui->tablePlayer->update();
		itemName->setFlags(Qt::ItemIsEnabled| Qt::ItemIsEditable);
		itemAvatar->setFlags(Qt::ItemIsEnabled| Qt::ItemIsEditable);
	}
}

QVector<QString> *NewLocalGame::getNames(){

	return nameList;
}

void NewLocalGame::update()
{

	comboBoxName1->clear();
	comboBoxName2->clear();
	comboBoxName3->clear();
	comboBoxName4->clear();
	comboBoxName5->clear();

	for(unsigned int i = 0; i < nameList->size(); ++i){
		comboBoxName1->addItem(QIcon(""), nameList->at(i));
		comboBoxName2->addItem(QIcon(""), nameList->at(i));
		comboBoxName3->addItem(QIcon(""), nameList->at(i));
		comboBoxName4->addItem(QIcon(""), nameList->at(i));
		comboBoxName5->addItem(QIcon(""), nameList->at(i));
	}

	QWidget::update();
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
