/********************************************************************************
** Form generated from reading UI file 'LoadWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADWINDOW_H
#define UI_LOADWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoadWindow
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QListView *listViews;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_4;
    QLabel *playerLabel2;
    QLabel *playerLabel1;
    QLabel *sizeLabel;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *loadButton;
    QPushButton *pushButton;

    void setupUi(QDialog *LoadWindow)
    {
        if (LoadWindow->objectName().isEmpty())
            LoadWindow->setObjectName(QStringLiteral("LoadWindow"));
        LoadWindow->resize(502, 473);
        LoadWindow->setModal(true);
        verticalLayout = new QVBoxLayout(LoadWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox = new QGroupBox(LoadWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        listViews = new QListView(groupBox);
        listViews->setObjectName(QStringLiteral("listViews"));
        listViews->setEditTriggers(QAbstractItemView::NoEditTriggers);

        horizontalLayout_2->addWidget(listViews);


        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(LoadWindow);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        playerLabel2 = new QLabel(groupBox_2);
        playerLabel2->setObjectName(QStringLiteral("playerLabel2"));

        formLayout->setWidget(3, QFormLayout::FieldRole, playerLabel2);

        playerLabel1 = new QLabel(groupBox_2);
        playerLabel1->setObjectName(QStringLiteral("playerLabel1"));

        formLayout->setWidget(2, QFormLayout::FieldRole, playerLabel1);

        sizeLabel = new QLabel(groupBox_2);
        sizeLabel->setObjectName(QStringLiteral("sizeLabel"));

        formLayout->setWidget(0, QFormLayout::FieldRole, sizeLabel);


        verticalLayout_2->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_3->addWidget(groupBox_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        loadButton = new QPushButton(LoadWindow);
        loadButton->setObjectName(QStringLiteral("loadButton"));

        horizontalLayout->addWidget(loadButton);

        pushButton = new QPushButton(LoadWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(LoadWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), LoadWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(LoadWindow);
    } // setupUi

    void retranslateUi(QDialog *LoadWindow)
    {
        LoadWindow->setWindowTitle(QApplication::translate("LoadWindow", "Charger uen partie", 0));
        groupBox->setTitle(QApplication::translate("LoadWindow", "Parties", 0));
        groupBox_2->setTitle(QApplication::translate("LoadWindow", "Informations", 0));
        label_2->setText(QApplication::translate("LoadWindow", "Joueur 1 : ", 0));
        label->setText(QApplication::translate("LoadWindow", "Taille : ", 0));
        label_4->setText(QApplication::translate("LoadWindow", "Joueur 2 : ", 0));
        playerLabel2->setText(QString());
        playerLabel1->setText(QString());
        sizeLabel->setText(QString());
        loadButton->setText(QApplication::translate("LoadWindow", "Charger", 0));
        pushButton->setText(QApplication::translate("LoadWindow", "Annuler", 0));
    } // retranslateUi

};

namespace Ui {
    class LoadWindow: public Ui_LoadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADWINDOW_H
