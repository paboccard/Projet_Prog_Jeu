#ifndef RULESOPTION_H
#define RULESOPTION_H

#include <QWidget>

namespace Ui {
class RulesOption;
}

class RulesOption : public QWidget
{
	Q_OBJECT

public:
	explicit RulesOption(QWidget *parent = 0);
	~RulesOption();

private slots:
	void on_buttonBack_clicked();

signals:
	void backOptions();

private:
	Ui::RulesOption *ui;
};

#endif // RULESOPTION_H
