#ifndef CONFIGGAMEWINDOW_H
#define CONFIGGAMEWINDOW_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class ConfigGameWindow;
}

class ConfigGameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigGameWindow(QWidget *parent = 0);
    ~ConfigGameWindow();

private:
    Ui::ConfigGameWindow *ui;
};

#endif // CONFIGGAMEWINDOW_H
