#ifndef CREATENETWORKGAME_H
#define CREATENETWORKGAME_H

#include <QWidget>

namespace Ui {
class CreateNetworkGame;
}

class CreateNetworkGame : public QWidget
{
	Q_OBJECT

public:
	explicit CreateNetworkGame(QWidget *parent = 0);
	~CreateNetworkGame();

	QString getName();
	int getNbrPlayers();

private slots:
	void on_buttonCreate_clicked();
	void on_buttonCancel_clicked();

signals:
	void accepted();
	void rejected();

private:
	Ui::CreateNetworkGame *ui;
};

#endif // CREATENETWORKGAME_H
