#ifndef NEWLOCALGAME_H
#define NEWLOCALGAME_H

#include <QWidget>
#include "../Shared/Profile.h"
#include "ProfilMenu.h"
#include <QTableWidgetItem>
#include <QComboBox>

namespace Ui {
	class NewLocalGame;
}

class NewLocalGame : public QWidget
{
		Q_OBJECT

	public:
		explicit NewLocalGame(QWidget *parent = 0);
		~NewLocalGame();
		QVector<QString> *getNames();
		QVector<Profile> *getProfiles();
		void update();


    public slots:
		void changeName1(int);
		void changeName2(int);
		void changeName3(int);
		void changeName4(int);
		void changeName5(int);
		void changeType(int);

	private slots:
		void on_buttonCancel_clicked();
		void on_buttonPlay_clicked();
		void on_buttonNewProfil_clicked();
        void on_spinNbPlayer_valueChanged(int arg1);

signals:
		void rejected();
		void accepted(int, QVector<Profile>);
		void newProfil();


	private:
		Ui::NewLocalGame *ui;
        Qt::ItemFlags flags; //= Qt::NoItemFlags;
		QVector<QString> *nameList;
		QVector<Profile> *profiles;
		QVector<Profile> players;
		QComboBox *comboBoxName1;
		QComboBox *comboBoxName2;
		QComboBox *comboBoxName3;
		QComboBox *comboBoxName4;
		QComboBox *comboBoxName5;
		QComboBox *comboBoxAvatar1;
		QComboBox *comboBoxAvatar2;
		QComboBox *comboBoxAvatar3;
		QComboBox *comboBoxAvatar4;
		QComboBox *comboBoxAvatar5;
        QComboBox *comboBoxType1;
        QComboBox *comboBoxType2;
        QComboBox *comboBoxType3;
        QComboBox *comboBoxType4;
        QComboBox *comboBoxType5;
        QComboBox *comboBoxColor1;
        QComboBox *comboBoxColor2;
        QComboBox *comboBoxColor3;
        QComboBox *comboBoxColor4;
        QComboBox *comboBoxColor5;
};

#endif // NEWLOCALGAME_H
