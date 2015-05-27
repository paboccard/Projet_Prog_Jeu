#ifndef SERVEROPTION_H
#define SERVEROPTION_H

#include <QWidget>

namespace Ui {
class ServerOption;
}

class ServerOption : public QWidget
{
	Q_OBJECT

public:
	explicit ServerOption(QWidget *parent = 0);
	~ServerOption();

private slots:
	void on_buttonAccept_clicked();
	void on_buttonCancel_clicked();

signals:
	void accepted();
	void rejected();

private:
	Ui::ServerOption *ui;
};

#endif // SERVEROPTION_H
