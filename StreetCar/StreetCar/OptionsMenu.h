#ifndef OPTIONSMENU_H
#define OPTIONSMENU_H

#include <QWidget>

namespace Ui {
class OptionsMenu;
}

class OptionsMenu : public QWidget
{
	Q_OBJECT

public:
	explicit OptionsMenu(QWidget *parent = 0);
	~OptionsMenu();

private slots:
	void on_buttonSound_clicked();
	void on_buttonServer_clicked();
	void on_buttonGraphics_clicked();
	void on_buttonRules_clicked();
	void on_buttonCredits_clicked();
	void on_buttonBack_clicked();

signals:
	void soundOption();
	void serverOption();
	void graphicsOption();
	void rulesOption();
	void creditsOption();
	void backMenu();

private:
	Ui::OptionsMenu *ui;
};

#endif // OPTIONSMENU_H
