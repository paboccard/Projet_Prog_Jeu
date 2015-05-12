#ifndef LOADWINDOW_H
#define LOADWINDOW_H

#include <QDialog>
#include "Game.h"
#include <vector>
#include <QItemSelection>

namespace Ui {
class LoadWindow;
}

class LoadWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoadWindow(QWidget *parent = 0);
    ~LoadWindow();
    void setList(std::vector<Game> l);

private slots:
    void indexMoved(QModelIndex index);
    void doubleClicked(QModelIndex index);

private:
    Ui::LoadWindow *ui;
    std::vector<Game> listGame;

    QString difficultyToStr(difficulty diff);
};

#endif // LOADWINDOW_H
