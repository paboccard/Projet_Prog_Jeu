#ifndef CREDITSOPTION_H
#define CREDITSOPTION_H

#include <QWidget>

namespace Ui {
class CreditsOption;
}

class CreditsOption : public QWidget
{
	Q_OBJECT

public:
	explicit CreditsOption(QWidget *parent = 0);
	~CreditsOption();

private slots:
	void on_buttonBack_clicked();

signals:
	void backOptions();

private:
	Ui::CreditsOption *ui;
};

#endif // CREDITSOPTION_H
