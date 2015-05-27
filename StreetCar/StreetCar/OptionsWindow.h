#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QWidget>

namespace Ui {
class OptionsWindow;
}

class OptionsWindow : public QWidget
{
	Q_OBJECT

public:
	explicit OptionsWindow(QWidget *parent = 0);
	~OptionsWindow();

private slots:
	void on_buttonSound_clicked();
	void on_buttonServer_clicked();
	void on_buttonGraphics_clicked();
	void on_buttonInstructions_clicked();
	void on_buttonCredits_clicked();
	void on_buttonBack_clicked();

signals:
	void soundOption();
	void serverOption();
	void graphicsOption();
	void instructionsOption();
	void creditsOption();
	void backMenu();

private:
	Ui::OptionsWindow *ui;
};

#endif // OPTIONSWINDOW_H
