/********************************************************************************
** Form generated from reading UI file 'GameWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Controller
{
public:
    QAction *configureAction;
    QAction *saveAction;
    QAction *loadAction;
    QAction *exitAction;
    QAction *actionNouvelle_partie;
    QAction *actionSauver_2;
    QAction *undoAction;
    QAction *redoAction;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *playerLabel1;
    QLabel *diffLabel1;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGraphicsView *graphicsView;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_4;
    QLabel *playerLabel2;
    QLabel *diffLabel2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *undoButton;
    QPushButton *redoButton;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *verticalSpacer_6;
    QFrame *line;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *newButton;
    QPushButton *exitButton;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuEdition;

    void setupUi(QMainWindow *Controller)
    {
        if (Controller->objectName().isEmpty())
            Controller->setObjectName(QStringLiteral("Controller"));
        Controller->resize(823, 546);
        configureAction = new QAction(Controller);
        configureAction->setObjectName(QStringLiteral("configureAction"));
        saveAction = new QAction(Controller);
        saveAction->setObjectName(QStringLiteral("saveAction"));
        loadAction = new QAction(Controller);
        loadAction->setObjectName(QStringLiteral("loadAction"));
        exitAction = new QAction(Controller);
        exitAction->setObjectName(QStringLiteral("exitAction"));
        actionNouvelle_partie = new QAction(Controller);
        actionNouvelle_partie->setObjectName(QStringLiteral("actionNouvelle_partie"));
        actionSauver_2 = new QAction(Controller);
        actionSauver_2->setObjectName(QStringLiteral("actionSauver_2"));
        undoAction = new QAction(Controller);
        undoAction->setObjectName(QStringLiteral("undoAction"));
        redoAction = new QAction(Controller);
        redoAction->setObjectName(QStringLiteral("redoAction"));
        centralWidget = new QWidget(Controller);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_3);

        playerLabel1 = new QLabel(centralWidget);
        playerLabel1->setObjectName(QStringLiteral("playerLabel1"));

        verticalLayout_2->addWidget(playerLabel1);

        diffLabel1 = new QLabel(centralWidget);
        diffLabel1->setObjectName(QStringLiteral("diffLabel1"));

        verticalLayout_2->addWidget(diffLabel1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        graphicsView->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);

        horizontalLayout_2->addWidget(graphicsView);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer_4 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_3->addItem(verticalSpacer_4);

        playerLabel2 = new QLabel(centralWidget);
        playerLabel2->setObjectName(QStringLiteral("playerLabel2"));

        verticalLayout_3->addWidget(playerLabel2);

        diffLabel2 = new QLabel(centralWidget);
        diffLabel2->setObjectName(QStringLiteral("diffLabel2"));

        verticalLayout_3->addWidget(diffLabel2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        undoButton = new QPushButton(centralWidget);
        undoButton->setObjectName(QStringLiteral("undoButton"));
        undoButton->setEnabled(true);

        horizontalLayout_5->addWidget(undoButton);

        redoButton = new QPushButton(centralWidget);
        redoButton->setObjectName(QStringLiteral("redoButton"));
        redoButton->setEnabled(true);

        horizontalLayout_5->addWidget(redoButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));

        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_6 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_6);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        newButton = new QPushButton(centralWidget);
        newButton->setObjectName(QStringLiteral("newButton"));

        horizontalLayout->addWidget(newButton);

        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        horizontalLayout->addWidget(exitButton);


        verticalLayout->addLayout(horizontalLayout);

        Controller->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Controller);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 823, 20));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QStringLiteral("menuEdition"));
        Controller->setMenuBar(menuBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuFichier->addAction(configureAction);
        menuFichier->addAction(saveAction);
        menuFichier->addAction(loadAction);
        menuFichier->addAction(exitAction);
        menuEdition->addAction(undoAction);
        menuEdition->addAction(redoAction);

        retranslateUi(Controller);
        QObject::connect(exitButton, SIGNAL(clicked()), Controller, SLOT(close()));

        QMetaObject::connectSlotsByName(Controller);
    } // setupUi

    void retranslateUi(QMainWindow *Controller)
    {
        Controller->setWindowTitle(QApplication::translate("Controller", "Jeux Gauffre", 0));
        configureAction->setText(QApplication::translate("Controller", "Configurer une partie", 0));
        saveAction->setText(QApplication::translate("Controller", "Sauver", 0));
        saveAction->setShortcut(QApplication::translate("Controller", "Ctrl+S", 0));
        loadAction->setText(QApplication::translate("Controller", "Charger", 0));
        loadAction->setShortcut(QApplication::translate("Controller", "Ctrl+O", 0));
        exitAction->setText(QApplication::translate("Controller", "Quitter", 0));
        actionNouvelle_partie->setText(QApplication::translate("Controller", "Nouvelle partie", 0));
        actionSauver_2->setText(QApplication::translate("Controller", "sauver", 0));
        undoAction->setText(QApplication::translate("Controller", "Annuler", 0));
        redoAction->setText(QApplication::translate("Controller", "Refaire", 0));
        playerLabel1->setText(QApplication::translate("Controller", "Player1", 0));
        diffLabel1->setText(QString());
        playerLabel2->setText(QApplication::translate("Controller", "Player2", 0));
        diffLabel2->setText(QString());
        undoButton->setText(QApplication::translate("Controller", "Annuler", 0));
        redoButton->setText(QApplication::translate("Controller", "Refaire", 0));
#ifndef QT_NO_TOOLTIP
        newButton->setToolTip(QApplication::translate("Controller", "Lance une nouvelle partie", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        newButton->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        newButton->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        newButton->setText(QApplication::translate("Controller", "Nouveau Jeu", 0));
        newButton->setShortcut(QApplication::translate("Controller", "Ctrl+N", 0));
        exitButton->setText(QApplication::translate("Controller", "Quitter", 0));
        exitButton->setShortcut(QApplication::translate("Controller", "Ctrl+Q", 0));
        menuFichier->setTitle(QApplication::translate("Controller", "Fichier", 0));
        menuEdition->setTitle(QApplication::translate("Controller", "Edition", 0));
    } // retranslateUi

};

namespace Ui {
    class Controller: public Ui_Controller {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
