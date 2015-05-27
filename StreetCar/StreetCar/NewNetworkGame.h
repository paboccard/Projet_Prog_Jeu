#ifndef NEWNETWORKGAME_H
#define NEWNETWORKGAME_H

#include <QWidget>

namespace Ui {
class NewNetworkGame;
}

class NewNetworkGame : public QWidget
{
	Q_OBJECT

public:
	explicit NewNetworkGame(QWidget *parent = 0);
	~NewNetworkGame();

private slots:
	void on_buttonConnect_clicked();
	void on_buttonRefresh_clicked();
	void on_buttonCancel_clicked();
	void on_buttonCreate_clicked();
	void on_buttonNext_clicked();

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
