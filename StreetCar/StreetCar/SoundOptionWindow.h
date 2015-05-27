#ifndef SOUNDOPTIONWINDOW_H
#define SOUNDOPTIONWINDOW_H

#include <QWidget>

namespace Ui {
class SoundOptionWindow;
}

class SoundOptionWindow : public QWidget
{
	Q_OBJECT

public:
	explicit SoundOptionWindow(QWidget *parent = 0);
	~SoundOptionWindow();

private:
	Ui::SoundOptionWindow *ui;
};

#endif // SOUNDOPTIONWINDOW_H
