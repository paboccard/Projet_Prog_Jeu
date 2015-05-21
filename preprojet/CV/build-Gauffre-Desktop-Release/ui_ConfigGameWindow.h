/********************************************************************************
** Form generated from reading UI file 'ConfigGameWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGGAMEWINDOW_H
#define UI_CONFIGGAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConfigGameWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *gameLabel;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *sizeGroupBox;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpinBox *widthSpinBox;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *heightSpinBox;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *modeGroupBox;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *pvpRadioButton;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *pvcRadioButton;
    QComboBox *difficultypvcComboBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *cvcRadioButton;
    QComboBox *difficultycvcComboBox1;
    QComboBox *difficultycvcComboBox2;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *startButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *ConfigGameWindow)
    {
        if (ConfigGameWindow->objectName().isEmpty())
            ConfigGameWindow->setObjectName(QStringLiteral("ConfigGameWindow"));
        ConfigGameWindow->resize(658, 379);
        ConfigGameWindow->setModal(true);
        verticalLayout_2 = new QVBoxLayout(ConfigGameWindow);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gameLabel = new QLabel(ConfigGameWindow);
        gameLabel->setObjectName(QStringLiteral("gameLabel"));
        QFont font;
        font.setPointSize(12);
        gameLabel->setFont(font);
        gameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(gameLabel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        sizeGroupBox = new QGroupBox(ConfigGameWindow);
        sizeGroupBox->setObjectName(QStringLiteral("sizeGroupBox"));
        verticalLayout_4 = new QVBoxLayout(sizeGroupBox);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(sizeGroupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        widthSpinBox = new QSpinBox(sizeGroupBox);
        widthSpinBox->setObjectName(QStringLiteral("widthSpinBox"));
        widthSpinBox->setMinimum(2);
        widthSpinBox->setMaximum(20);
        widthSpinBox->setValue(5);

        horizontalLayout_4->addWidget(widthSpinBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(sizeGroupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        heightSpinBox = new QSpinBox(sizeGroupBox);
        heightSpinBox->setObjectName(QStringLiteral("heightSpinBox"));
        heightSpinBox->setMinimum(2);
        heightSpinBox->setMaximum(20);
        heightSpinBox->setValue(4);

        horizontalLayout_2->addWidget(heightSpinBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(sizeGroupBox);

        modeGroupBox = new QGroupBox(ConfigGameWindow);
        modeGroupBox->setObjectName(QStringLiteral("modeGroupBox"));
        verticalLayout_3 = new QVBoxLayout(modeGroupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pvpRadioButton = new QRadioButton(modeGroupBox);
        pvpRadioButton->setObjectName(QStringLiteral("pvpRadioButton"));
        pvpRadioButton->setChecked(false);

        verticalLayout_3->addWidget(pvpRadioButton);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pvcRadioButton = new QRadioButton(modeGroupBox);
        pvcRadioButton->setObjectName(QStringLiteral("pvcRadioButton"));
        pvcRadioButton->setChecked(true);

        horizontalLayout_6->addWidget(pvcRadioButton);

        difficultypvcComboBox = new QComboBox(modeGroupBox);
        difficultypvcComboBox->setObjectName(QStringLiteral("difficultypvcComboBox"));
        difficultypvcComboBox->setEnabled(true);

        horizontalLayout_6->addWidget(difficultypvcComboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        cvcRadioButton = new QRadioButton(modeGroupBox);
        cvcRadioButton->setObjectName(QStringLiteral("cvcRadioButton"));

        horizontalLayout_5->addWidget(cvcRadioButton);

        difficultycvcComboBox1 = new QComboBox(modeGroupBox);
        difficultycvcComboBox1->setObjectName(QStringLiteral("difficultycvcComboBox1"));
        difficultycvcComboBox1->setEnabled(false);

        horizontalLayout_5->addWidget(difficultycvcComboBox1);

        difficultycvcComboBox2 = new QComboBox(modeGroupBox);
        difficultycvcComboBox2->setObjectName(QStringLiteral("difficultycvcComboBox2"));
        difficultycvcComboBox2->setEnabled(false);

        horizontalLayout_5->addWidget(difficultycvcComboBox2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout_2->addWidget(modeGroupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        startButton = new QPushButton(ConfigGameWindow);
        startButton->setObjectName(QStringLiteral("startButton"));

        horizontalLayout->addWidget(startButton);

        cancelButton = new QPushButton(ConfigGameWindow);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(ConfigGameWindow);
        QObject::connect(cvcRadioButton, SIGNAL(toggled(bool)), difficultycvcComboBox1, SLOT(setEnabled(bool)));
        QObject::connect(pvcRadioButton, SIGNAL(toggled(bool)), difficultypvcComboBox, SLOT(setEnabled(bool)));
        QObject::connect(cvcRadioButton, SIGNAL(toggled(bool)), difficultycvcComboBox2, SLOT(setEnabled(bool)));
        QObject::connect(cancelButton, SIGNAL(clicked()), ConfigGameWindow, SLOT(close()));
        QObject::connect(startButton, SIGNAL(clicked()), ConfigGameWindow, SLOT(accept()));

        QMetaObject::connectSlotsByName(ConfigGameWindow);
    } // setupUi

    void retranslateUi(QDialog *ConfigGameWindow)
    {
        ConfigGameWindow->setWindowTitle(QApplication::translate("ConfigGameWindow", "Configuration", 0));
        gameLabel->setText(QApplication::translate("ConfigGameWindow", "Configuration jeu Gaufre", 0));
        sizeGroupBox->setTitle(QApplication::translate("ConfigGameWindow", "Taille de la gaufre", 0));
        label_3->setText(QApplication::translate("ConfigGameWindow", "Largeur :", 0));
        widthSpinBox->setPrefix(QString());
        label->setText(QApplication::translate("ConfigGameWindow", "Hauteur :", 0));
        heightSpinBox->setPrefix(QString());
        modeGroupBox->setTitle(QApplication::translate("ConfigGameWindow", "Mode", 0));
        pvpRadioButton->setText(QApplication::translate("ConfigGameWindow", "Humain vs Humain", 0));
        pvcRadioButton->setText(QApplication::translate("ConfigGameWindow", "Humain vs Machine", 0));
        difficultypvcComboBox->clear();
        difficultypvcComboBox->insertItems(0, QStringList()
         << QApplication::translate("ConfigGameWindow", "Jeu al\303\251atoire", 0)
         << QApplication::translate("ConfigGameWindow", "Coup gagnant / perdant", 0)
         << QApplication::translate("ConfigGameWindow", "Minimax", 0)
        );
        cvcRadioButton->setText(QApplication::translate("ConfigGameWindow", "Machine vs Machine", 0));
        difficultycvcComboBox1->clear();
        difficultycvcComboBox1->insertItems(0, QStringList()
         << QApplication::translate("ConfigGameWindow", "Jeu al\303\251atoire", 0)
         << QApplication::translate("ConfigGameWindow", "Coup gagnant / perdant", 0)
         << QApplication::translate("ConfigGameWindow", "Minimax", 0)
        );
        difficultycvcComboBox2->clear();
        difficultycvcComboBox2->insertItems(0, QStringList()
         << QApplication::translate("ConfigGameWindow", "Jeu al\303\251atoire", 0)
         << QApplication::translate("ConfigGameWindow", "Coup gagnant / perdant", 0)
         << QApplication::translate("ConfigGameWindow", "Minimax", 0)
        );
        startButton->setText(QApplication::translate("ConfigGameWindow", "Commencer", 0));
#ifndef QT_NO_WHATSTHIS
        cancelButton->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        cancelButton->setText(QApplication::translate("ConfigGameWindow", "Annuler", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfigGameWindow: public Ui_ConfigGameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGGAMEWINDOW_H
