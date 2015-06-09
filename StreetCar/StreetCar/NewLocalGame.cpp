#include "NewLocalGame.h"
#include "ui_NewLocalGame.h"
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QtGui>
#include <iostream>

using namespace std;

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
	int w = ui->tablePlayer->verticalHeader()->width() + 40;
    for (int i = 0; i < ui->tablePlayer->columnCount(); i++)
		  w += ui->tablePlayer->columnWidth(i);
	int h = ui->tablePlayer->horizontalHeader()->height() + 4;
	for (int i = 0; i < ui->tablePlayer->rowCount(); i++){
		  h += ui->tablePlayer->rowHeight(i);
		ui->tablePlayer->setRowHeight(i,40);
	}

    //flags for no action
    flags = Qt::NoItemFlags;

	profiles = new QVector<Profile>;

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
	avatarList.push_back(QIcon(":/avatars/machine"));


	for(int i = 0; i < avatarList.size(); ++i){
		comboBoxAvatar1->addItem(avatarList.at(i), QString(""));
		comboBoxAvatar2->addItem(avatarList.at(i), QString(""));
		comboBoxAvatar3->addItem(avatarList.at(i), QString(""));
		comboBoxAvatar4->addItem(avatarList.at(i), QString(""));
		comboBoxAvatar5->addItem(avatarList.at(i), QString(""));
	}
	comboBoxAvatar1->setDisabled(true);
	comboBoxAvatar2->setDisabled(true);
	comboBoxAvatar3->setDisabled(true);
	comboBoxAvatar4->setDisabled(true);
	comboBoxAvatar5->setDisabled(true);

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
	for(int i = 0; i < nameList->size(); ++i){
		comboBoxType1->addItem(QIcon(""), nameList->at(i));
		comboBoxType2->addItem(QIcon(""), nameList->at(i));
		comboBoxType3->addItem(QIcon(""), nameList->at(i));
		comboBoxType4->addItem(QIcon(""), nameList->at(i));
		comboBoxType5->addItem(QIcon(""), nameList->at(i));
	}

	ordiList = new QVector<QString>();
    ordiList->push_back("Automate1");
    ordiList->push_back("Automate2");
    ordiList->push_back("Automate3");
    ordiList->push_back("Automate4");
    ordiList->push_back("Automate5");

	//signal gestion name combobox
	connect(comboBoxName1, SIGNAL(currentIndexChanged(int)), this, SLOT(changeName1(int)));
	connect(comboBoxName2, SIGNAL(currentIndexChanged(int)), this, SLOT(changeName2(int)));
	connect(comboBoxName3, SIGNAL(currentIndexChanged(int)), this, SLOT(changeName3(int)));
	connect(comboBoxName4, SIGNAL(currentIndexChanged(int)), this, SLOT(changeName4(int)));
	connect(comboBoxName5, SIGNAL(currentIndexChanged(int)), this, SLOT(changeName5(int)));

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
    typeList.push_back("Automate niv1");
    typeList.push_back("Automate niv2");

	for(int i = 0; i < typeList.size(); ++i){
		comboBoxType1->addItem(QIcon(""), typeList.at(i));
		comboBoxType2->addItem(QIcon(""), typeList.at(i));
		comboBoxType3->addItem(QIcon(""), typeList.at(i));
		comboBoxType4->addItem(QIcon(""), typeList.at(i));
		comboBoxType5->addItem(QIcon(""), typeList.at(i));
	}

	//signal gestion type combobox
	connect(comboBoxType1, SIGNAL(currentIndexChanged(int)), this, SLOT(changeType1(int)));
	connect(comboBoxType2, SIGNAL(currentIndexChanged(int)), this, SLOT(changeType2(int)));
	connect(comboBoxType3, SIGNAL(currentIndexChanged(int)), this, SLOT(changeType3(int)));

    // two row visible at first
    ui->tablePlayer->setRowHidden(2, true);
    ui->tablePlayer->setRowHidden(3, true);
    ui->tablePlayer->setRowHidden(4, true);

	// type first line human
	for(int i = 0; i < comboBoxName1->count(); i++){
		if(comboBoxName1->itemText(i).toStdString() == profiles->at(0).name){
			comboBoxName1->setCurrentIndex(i);
		}
	}

	//comboBoxAvatar1->setCurrentIndex(profiles->at(0).avatar);
	comboBoxName1->setDisabled(true);
}

NewLocalGame::~NewLocalGame()
{
	delete ui;
}

void NewLocalGame::changeName1(int index){
	ui->tablePlayer->update();
	for(int i = 0; i < profiles->size(); i++){
		if(profiles->at(i).name == comboBoxName1->itemText(index).toStdString()){
			comboBoxAvatar1->setCurrentIndex(profiles->at(i).avatar);
		}
	}
}

void NewLocalGame::changeName2(int index){
	ui->tablePlayer->update();
	for(int i = 1; i < profiles->size(); i++){
		if(profiles->at(i).name == comboBoxName2->itemText(index).toStdString()){
			comboBoxAvatar2->setCurrentIndex(profiles->at(i).avatar);
		}
	}
}

void NewLocalGame::changeName3(int index){
	ui->tablePlayer->update();
	for(int i = 1; i < profiles->size(); i++){
		if(profiles->at(i).name == comboBoxName3->itemText(index).toStdString()){
			comboBoxAvatar3->setCurrentIndex(profiles->at(i).avatar);
		}
	}
}

void NewLocalGame::changeName4(int index){
	ui->tablePlayer->update();
	for(int i = 1; i < profiles->size(); i++){
		if(profiles->at(i).name == comboBoxName4->itemText(index).toStdString()){
			comboBoxAvatar4->setCurrentIndex(profiles->at(i).avatar);
		}
	}
}

void NewLocalGame::changeName5(int index){
	ui->tablePlayer->update();
	for(int i = 1; i < profiles->size(); i++){
		if(profiles->at(i).name == comboBoxName5->itemText(index).toStdString()){
			comboBoxAvatar5->setCurrentIndex(profiles->at(i).avatar);
		}
	}
}

void NewLocalGame::changeType1(int index) {
	if(index==0){ //humain
		comboBoxName1->clear();
		for(int i = 0; i < nameList->size(); ++i){
			comboBoxName1->addItem(QIcon(""), nameList->at(i));
		}
		comboBoxAvatar1->update();
		for(int i = 0; i < comboBoxName1->count(); i++){
			if(comboBoxName1->itemText(i).toStdString() == profiles->at(0).name){
				comboBoxName1->setCurrentIndex(i);
			}
		}
		comboBoxAvatar1->setCurrentIndex(profiles->at(0).avatar);
		comboBoxName1->setDisabled(true);
	}else{
		comboBoxName1->update();
		comboBoxAvatar1->update();
		comboBoxAvatar1->setCurrentIndex(6);
		comboBoxName1->clear();
		for(int i = 0; i < ordiList->size(); ++i){
			comboBoxName1->addItem(QIcon(""), ordiList->at(i));
		}
		comboBoxName1->setDisabled(false);
	}
}

void NewLocalGame::changeType2(int index) {
	if(index==0){ //humain
		comboBoxName2->clear();
		for(int i = 1; i < nameList->size(); ++i){
			comboBoxName2->addItem(QIcon(""), nameList->at(i));
		}
		comboBoxAvatar2->update();
	}else{
		comboBoxName2->update();
		comboBoxAvatar2->update();
		comboBoxAvatar2->setCurrentIndex(6);
		comboBoxName2->clear();
		for(int i = 0; i < ordiList->size(); ++i){
			comboBoxName2->addItem(QIcon(""), ordiList->at(i));
		}
	}
}

void NewLocalGame::changeType3(int index) {
	if(index==0){ //humain
		comboBoxName3->clear();
		for(int i = 1; i < nameList->size(); ++i){
			comboBoxName3->addItem(QIcon(""), nameList->at(i));
		}
		comboBoxAvatar3->update();
	}else{
		comboBoxName3->update();
		comboBoxAvatar3->update();
		comboBoxAvatar3->setCurrentIndex(6);
		comboBoxName3->clear();
		for(int i = 0; i < ordiList->size(); ++i){
			comboBoxName3->addItem(QIcon(""), ordiList->at(i));
		}
	}
}

void NewLocalGame::changeType4(int index) {
	if(index==0){ //humain
		comboBoxName4->clear();
		for(int i = 1; i < nameList->size(); ++i){
			comboBoxName4->addItem(QIcon(""), nameList->at(i));
		}
		comboBoxAvatar4->update();
	}else{
		comboBoxName4->update();
		comboBoxAvatar4->update();
		comboBoxAvatar4->setCurrentIndex(6);
		comboBoxName4->clear();
		for(int i = 0; i < ordiList->size(); ++i){
			comboBoxName4->addItem(QIcon(""), ordiList->at(i));
		}
	}
}

void NewLocalGame::changeType5(int index) {
	if(index==0){ //humain
		comboBoxName5->clear();
		for(int i = 1; i < nameList->size(); ++i){
			comboBoxName5->addItem(QIcon(""), nameList->at(i));
		}
		comboBoxAvatar5->update();
	}else{
		comboBoxName5->update();
		comboBoxAvatar5->update();
		comboBoxAvatar5->setCurrentIndex(6);
		comboBoxName5->clear();
		for(int i = 0; i < ordiList->size(); ++i){
			comboBoxName5->addItem(QIcon(""), ordiList->at(i));
		}
	}
}

QVector<QString> *NewLocalGame::getNames(){
	return nameList;
}

QVector<Profile> *NewLocalGame::getProfiles(){
	return profiles;
}

void NewLocalGame::hideDelProfile(){
    ui->buttonDelProfil->hide();
}

void NewLocalGame::showDelProfile(){
    ui->buttonDelProfil->show();
}


void NewLocalGame::update(){
	comboBoxName1->clear();
	comboBoxName2->clear();
	comboBoxName3->clear();
	comboBoxName4->clear();
	comboBoxName5->clear();

	for(int i = 0; i < nameList->size(); ++i){
		comboBoxName1->addItem(QIcon(""), nameList->at(i));
	}
	for(int i = 1; i < nameList->size(); ++i){
		comboBoxName2->addItem(QIcon(""), nameList->at(i));
		comboBoxName3->addItem(QIcon(""), nameList->at(i));
		comboBoxName4->addItem(QIcon(""), nameList->at(i));
		comboBoxName5->addItem(QIcon(""), nameList->at(i));
	}
	comboBoxAvatar1->update();
	comboBoxAvatar2->update();
	comboBoxAvatar3->update();
	comboBoxAvatar4->update();
	comboBoxAvatar5->update();

	comboBoxType1->update();
	comboBoxType2->update();
	comboBoxType3->update();
	comboBoxType4->update();
	comboBoxType5->update();

	QWidget::update();
}

void NewLocalGame::on_buttonCancel_clicked()
{
	emit rejected();
}

void NewLocalGame::on_buttonPlay_clicked()
{
	if(ui->spinNbPlayer->value()==2 && comboBoxName2->currentText().toStdString().empty()){
        QMessageBox::information(this, tr("Nombre de joueur insuffisant"), tr("Ajouter un autre joueur pour pouvoir jouer"));
	}else if(ui->spinNbPlayer->value()==3 && (comboBoxName2->currentText().toStdString().empty()||comboBoxName3->currentText().toStdString().empty())){
        QMessageBox::information(this, tr("Nombre de joueur insuffisant"), tr("Ajouter un autre joueur pour pouvoir jouer"));
	}else if(ui->spinNbPlayer->value()==4 && (comboBoxName2->currentText().toStdString().empty()||comboBoxName3->currentText().toStdString().empty()||comboBoxName4->currentText().toStdString().empty())){
        QMessageBox::information(this, tr("Nombre de joueur insuffisant"), tr("Ajouter un autre joueur pour pouvoir jouer"));
	}else if(ui->spinNbPlayer->value()==5 && (comboBoxName2->currentText().toStdString().empty()||comboBoxName3->currentText().toStdString().empty()||comboBoxName4->currentText().toStdString().empty() || comboBoxName5->currentText().toStdString().empty())){
        QMessageBox::information(this, tr("Nombre de joueur insuffisant"), tr("Ajouter un autre joueur pour pouvoir jouer"));
	}else{
		//players list
		players.push_back(Profile(comboBoxName1->currentText().toStdString(), comboBoxAvatar1->currentIndex(), comboBoxType1->currentIndex())); //first line tab
		players.push_back(Profile(comboBoxName2->currentText().toStdString(), comboBoxAvatar2->currentIndex(), comboBoxType2->currentIndex())); //second line tab

		if(ui->spinNbPlayer->value() >= 3){
			players.push_back(Profile(comboBoxName3->currentText().toStdString(), comboBoxAvatar3->currentIndex(), comboBoxType3->currentIndex())); //third line tab
		}
		if(ui->spinNbPlayer->value() >= 4){
			players.push_back(Profile(comboBoxName4->currentText().toStdString(), comboBoxAvatar4->currentIndex(), comboBoxType4->currentIndex())); //fourth line tab
		}
		if(ui->spinNbPlayer->value() == 5){
			players.push_back(Profile(comboBoxName5->currentText().toStdString(), comboBoxAvatar5->currentIndex(), comboBoxType5->currentIndex())); //fifth line tab
		}
		emit accepted(ui->spinNbPlayer->value(), players);
	}
}

void NewLocalGame::on_buttonNewProfil_clicked()
{
	emit newProfil();
}

void NewLocalGame::on_buttonDelProfil_clicked()
{
	emit deleteProfil();
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
