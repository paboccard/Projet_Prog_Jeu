#include "ButtonMenu.h"
#include <QtGui>

ButtonMenu::ButtonMenu(QLabel* l, QString n, QWidget* parent) : QPushButton(n,parent)
{
    label = l;
    name = n;
}

ButtonMenu::~ButtonMenu(){

}

void ButtonMenu::enterEvent(QEvent *event)
{
    this->QPushButton::enterEvent(event);
    label->show();

    QPropertyAnimation *animation = new QPropertyAnimation(label, "geometry");
	animation->setDuration(1500);
    animation->setStartValue(QRect(this->x()-50, this->y()+5, this->width()/4, this->height()));
    animation->setEndValue(QRect(this->x()+this->width(),  this->y()+5, this->width()/4, this->height()));
    animation->start();
}

void ButtonMenu::leaveEvent(QEvent *event)
{
    this->QPushButton::leaveEvent(event);
    label->hide();
}
