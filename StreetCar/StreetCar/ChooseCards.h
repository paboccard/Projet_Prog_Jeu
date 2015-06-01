#ifndef CHOOSECARDS_H
#define CHOOSECARDS_H

#include <QWidget>

namespace Ui {
class ChooseCards;
}

class ChooseCards : public QWidget
{
	Q_OBJECT

public:
	explicit ChooseCards(QWidget *parent = 0);
	~ChooseCards();

private slots:
	void on_buttonCardLine1_clicked();
	void on_buttonCardLine2_clicked();
	void on_buttonCardLine3_clicked();
	void on_buttonCardLine4_clicked();
	void on_buttonCardLine5_clicked();
	void on_buttonCardLine6_clicked();
	void on_buttonCardLine7_clicked();
	void on_buttonCardLine8_clicked();
	void on_buttonCardLine9_clicked();
	void on_buttonCardLine10_clicked();
	void on_buttonCardLine11_clicked();
	void on_buttonCardLine12_clicked();

	void on_groupBox_clicked();

signals:
	void accepted();

private:
	Ui::ChooseCards *ui;
    //bool isSelect=false;
};

#endif // CHOOSECARDS_H
