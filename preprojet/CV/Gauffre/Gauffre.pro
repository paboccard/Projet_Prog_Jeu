#-------------------------------------------------
#
# Project created by QtCreator 2015-05-11T13:25:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gauffre
TEMPLATE = app


SOURCES += main.cpp\
        Controller.cpp \
    ConfigGameWindow.cpp \
    ../../Automata/solver.cpp

HEADERS  += Controller.h \
    ConfigGameWindow.h \
    ../../Utils.h \
    ../../Utils.h \
    ../../Automata/solver.h

FORMS    += GameWindow.ui \
    ConfigGameWindow.ui
