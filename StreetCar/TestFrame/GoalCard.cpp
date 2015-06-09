#include "GoalCard.h"

#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>

GoalCard::GoalCard(QWidget *parent) :
	QLabel(parent)
{
	setPixmap(QPixmap(":/cards/cartesBack").scaledToHeight(80));
	setCursor(Qt::PointingHandCursor);

	dialog = new QDialog(this);
	dialog->setModal(true);
	QVBoxLayout *layout = new QVBoxLayout(dialog);

	labelDialog = new QLabel();
	layout->addWidget(labelDialog);
	QPushButton *buttonOk = new QPushButton(tr("Ok"));

	layout->addWidget(buttonOk);
	connect(buttonOk, SIGNAL(clicked()), dialog, SLOT(accept()));
}

void GoalCard::setPixmapToShow(QPixmap p)
{
	labelDialog->setPixmap(p.scaledToWidth(300));
}

void GoalCard::mousePressEvent(QMouseEvent *e)
{
	if (QMessageBox::Ok == QMessageBox::question(this, tr("Afficher la carte"), QString::fromUtf8("La carte va être retourné temporairement. Attention aux regards indiscret."),	QMessageBox::Ok | QMessageBox::Cancel)){
		dialog->show();
	}

}
