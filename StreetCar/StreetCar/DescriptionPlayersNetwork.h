#ifndef DESCRIPTIONPLAYERSNETWORK_H
#define DESCRIPTIONPLAYERSNETWORK_H

#include <QWidget>
#include "../Shared/Profile.h"
#include "../Shared/Player.h"
#include <vector>

namespace Ui {
class DescriptionPlayersNetwork;
}

class DescriptionPlayersNetwork : public QWidget
{
	Q_OBJECT

public:
	explicit DescriptionPlayersNetwork(QWidget *parent = 0);
	~DescriptionPlayersNetwork();
	void addPlayer(Profile p);
	void setGameName(QString s);
	void show(bool host = false);

	public slots:

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
