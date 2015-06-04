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

    void on_comboBoxResolution_currentIndexChanged(int index);

signals:
    void accepted(bool, int, int);
	void rejected();

private:
	Ui::GraphicsOption *ui;
    bool fullScreen;
    int w, h;
};

#endif // GRAPHICSOPTION_H
