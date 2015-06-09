#ifndef NEWNETWORKGAME_H
#define NEWNETWORKGAME_H

#include <QWidget>
#include <vector>
#include "../Shared/Utils.h"

namespace Ui {
class NewNetworkGame;
}

class NewNetworkGame : public QWidget
{
	Q_OBJECT

public:
	explicit NewNetworkGame(QWidget *parent = 0);
	~NewNetworkGame();

	QString getIpServer();
	void setServers(std::vector<GameNetwork> v);
	void show();
	int getNum();

private slots:
	void on_buttonConnect_clicked();
	void on_buttonRefresh_clicked();
	void on_buttonCancel_clicked();
	void on_buttonCreate_clicked();
	void on_buttonChoose_clicked();

	void on_tableGame_itemSelectionChanged();

public slots:
	void connectedTotheServer();

	signals:
	void connected();
	void refreshed();
	void rejected();
	void created();
	void accepted();

private:
	Ui::NewNetworkGame *ui;
};

#endif // NEWNETWORKGAME_H
