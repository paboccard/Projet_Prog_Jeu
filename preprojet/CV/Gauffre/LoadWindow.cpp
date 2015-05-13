#include "LoadWindow.h"
#include "ui_LoadWindow.h"
#include <QStringListModel>
#include <QStringList>
#include <iostream>

using namespace std;

LoadWindow::LoadWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadWindow)
{
    ui->setupUi(this);
    connect(ui->listViews, SIGNAL(activated(QModelIndex)), this, SLOT(indexMoved(QModelIndex)));
    connect(ui->listViews, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(doubleClicked(QModelIndex)));
    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(slotLoad()));
}

LoadWindow::~LoadWindow()
{
    delete ui;
}

void LoadWindow::setList(vector<Game> l)
{
    cout << l.size() << endl;
    listGame = l;
    QStringList gameNameList;
    for (int i = 0; i < listGame.size(); i ++) {
        gameNameList.append(QString::fromStdString(listGame[i].name));
        cout << listGame[i].name << endl;
    }
    ui->listViews->setModel(new QStringListModel(gameNameList));
}

void LoadWindow::indexMoved(QModelIndex index)
{
    Game g = listGame[index.row()];
    cout << "selected " << index.row() << endl;
    ui->sizeLabel->setText(QString::number(g.width) + " * " + QString::number(g.height));
    switch (g.gameMode){
        case PvP:
            ui->playerLabel1->setText(tr("Joueur"));
            ui->playerLabel2->setText(tr("Joueur"));
        case PvC:
            ui->playerLabel1->setText(tr("Joueur"));
            ui->playerLabel2->setText(tr("Ordinateur ") + difficultyToStr(g.diff1));
        case CvC:
            ui->playerLabel1->setText(tr("Ordinateur ") + difficultyToStr(g.diff1));
            ui->playerLabel2->setText(tr("Ordinateur ") + difficultyToStr(g.diff2));
            break;
    }

}

QString LoadWindow::difficultyToStr(difficulty diff){
    switch(diff){
    case Easy:
        return tr("Aléatoire");
        break;
    case Medium:
        return tr("Coup gagnant / perdant");
        break;
    case Hard:
        return tr("Minimax");
        break;
    default:
        return "";
        break;
    }
}

void LoadWindow::doubleClicked(QModelIndex index)
{
    cout << "double cliecked : " << index.row() << endl;
    emit(loadGame(listGame[index.row()]));
}

void LoadWindow::slotLoad()
{

}
