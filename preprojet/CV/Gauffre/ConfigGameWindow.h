#ifndef CONFIGGAMEWINDOW_H
#define CONFIGGAMEWINDOW_H

#include <QWidget>
#include <QDialog>
#include "../../Utils.h"

namespace Ui {
class ConfigGameWindow;
}

class ConfigGameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigGameWindow(QWidget *parent = 0);
    ~ConfigGameWindow();
    int getWidth();
    int getHeight();
    mode getMode();
    difficulty getDiff1();
    difficulty getDiff2();

private:
    Ui::ConfigGameWindow *ui;
};

#endif // CONFIGGAMEWINDOW_H
