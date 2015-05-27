#ifndef LOADSAVEGAME_H
#define LOADSAVEGAME_H

#include <QWidget>

namespace Ui {
class LoadSaveGame;
}

class LoadSaveGame : public QWidget
{
	Q_OBJECT

public:
	explicit LoadSaveGame(QWidget *parent = 0);
	~LoadSaveGame();

private slots:
	void on_buttonAccept_clicked();
	void on_buttonCancel_clicked();
	void on_buttonDelete_clicked();
	void on_buttonSave_clicked();

signals:
	void accepted();
	void rejected();
	void deleted();
	void saved();

private:
	Ui::LoadSaveGame *ui;
};

#endif // LOADSAVEGAME_H
