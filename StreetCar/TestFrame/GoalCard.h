#ifndef GOALCARD_H
#define GOALCARD_H

#include <QLabel>

class GoalCard : public QLabel
{
		Q_OBJECT
	public:
		explicit GoalCard(QWidget *parent = 0);
		void setPixmapToShow(QPixmap p);

	signals:

	public slots:

	protected:
		void mousePressEvent(QMouseEvent *e);


	private:
		QLabel *labelDialog;
		QDialog *dialog;
};

#endif // GOALCARD_H
