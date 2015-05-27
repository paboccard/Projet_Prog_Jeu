#ifndef DESCRIPTIONPLAYERSNETWORK_H
#define DESCRIPTIONPLAYERSNETWORK_H

#include <QWidget>

namespace Ui {
class DescriptionPlayersNetwork;
}

class DescriptionPlayersNetwork : public QWidget
{
	Q_OBJECT

public:
	explicit DescriptionPlayersNetwork(QWidget *parent = 0);
	~DescriptionPlayersNetwork();

private slots:
	void on_buttonExit_clicked();
	void on_buttonPlay_clicked();

signals:
	void accepted();
	void rejected();

private:
	Ui::DescriptionPlayersNetwork *ui;
};

#endif // DESCRIPTIONPLAYERSNETWORK_H