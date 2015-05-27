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
    BoardWidget.cpp \
    SoundOption.cpp \
    OptionsMenu.cpp \
    ServerOption.cpp \
    RulesOption.cpp \
    GraphicsOption.cpp \
    CreditsOption.cpp \
    LoadSaveGame.cpp \
    NewNetworkGame.cpp \
    DescriptionPlayersNetwork.cpp

HEADERS  += MainWindow.h \
    MainMenu.h \
    NewLocalGame.h \
    ProfilMenu.h \
    BoardWidget.h \
    SoundOption.h \
    OptionsMenu.h \
    ServerOption.h \
    RulesOption.h \
    GraphicsOption.h \
    CreditsOption.h \
    LoadSaveGame.h \
    NewNetworkGame.h \
    DescriptionPlayersNetwork.h

FORMS    += MainWindow.ui \
    MainMenu.ui \
    NewLocalGame.ui \
    ProfilMenu.ui \
    Board.ui \
    SoundOption.ui \
    OptionsMenu.ui \
    ServerOption.ui \
    RulesOption.ui \
    GraphicsOption.ui \
    CreditsOption.ui \
    LoadSaveGame.ui \
    NewNetworkGame.ui \
    DescriptionPlayersNetwork.ui

RESOURCES +=
