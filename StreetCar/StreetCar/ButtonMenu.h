#ifndef BUTTONMENU_H
#define BUTTONMENU_H
#include <QLabel>
#include <QAbstractButton>
#include <QPushButton>
#include <QWidget>

class ButtonMenu : public QPushButton
{
public:
    ButtonMenu(QLabel*, QString, QWidget *);
    ~ButtonMenu();

protected:
void enterEvent(QEvent *event);
void leaveEvent(QEvent *event);

private:
    QLabel* label;
    QString name;
};

#endif // BUTTONMENU_H

