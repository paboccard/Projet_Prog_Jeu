#-------------------------------------------------
#
# Project created by QtCreator 2015-05-26T21:50:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StreetCar
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    MainMenu.cpp \
    NewLocalGame.cpp \
    ProfilMenu.cpp \
    BoardWidget.cpp

HEADERS  += MainWindow.h \
    MainMenu.h \
    NewLocalGame.h \
    ProfilMenu.h \
    BoardWidget.h

FORMS    += MainWindow.ui \
    MainMenu.ui \
    NewLocalGame.ui \
    ProfilMenu.ui \
    Board.ui
