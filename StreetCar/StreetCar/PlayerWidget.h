#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>
#include "../Shared/Player.h"
#include "../TestFrame/HandWidget.h"

namespace Ui {
class PlayerWidget;
}

class PlayerWidget : public QWidget
{
		Q_OBJECT

	public:
		explicit PlayerWidget(QWidget *parent = 0);
		PlayerWidget(Player* p);
		~PlayerWidget();

	private:
		Player* player;
		HandWidget *hand;
		Ui::PlayerWidget *ui;
};

#endif // PLAYERWIDGET_H
