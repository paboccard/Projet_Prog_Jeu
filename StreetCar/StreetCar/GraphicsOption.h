#ifndef GRAPHICSOPTION_H
#define GRAPHICSOPTION_H

#include <QWidget>

namespace Ui {
class GraphicsOption;
}

class GraphicsOption : public QWidget
{
	Q_OBJECT

public:
	explicit GraphicsOption(QWidget *parent = 0);
	~GraphicsOption();

private slots:
	void on_buttonAccept_clicked();
	void on_buttonCancel_clicked();

signals:
	void accepted();
	void rejected();

private:
	Ui::GraphicsOption *ui;
};

#endif // GRAPHICSOPTION_H
