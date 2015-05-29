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
    ServerOption.cpp \
    RulesOption.cpp \
    GraphicsOption.cpp \
    CreditsOption.cpp \
    LoadSaveGame.cpp \
    NewNetworkGame.cpp \
    DescriptionPlayersNetwork.cpp \
    PlayerWidget.cpp \
    TileWidget.cpp \
    OptionsMenu.cpp \
    ../Shared/Board.cpp \
    ../Shared/Card.cpp \
    ../Shared/Game.cpp \
    ../Shared/InitGame.cpp \
    ../Shared/IWantPlay.cpp \
    ../Shared/NewPlayerAdd.cpp \
    ../Shared/Pile.cpp \
    ../Shared/PilePlayer.cpp \
    ../Shared/PileTarget.cpp \
    ../Shared/PileWhenTravel.cpp \
    ../Shared/PlayedTile.cpp \
    ../Shared/PlayedTravel.cpp \
    ../Shared/Player.cpp \
    ../Shared/PlayTile.cpp \
    ../Shared/PlayTravel.cpp \
    ../Shared/Point.cpp \
    ../Shared/Profile.cpp \
    ../Shared/Square.cpp \
    ../Shared/StartedTravel.cpp \
    ../Shared/StartGame.cpp \
    ../Shared/StartTravel.cpp \
    ../Shared/Stop.cpp \
    ../Shared/StoppedTravel.cpp \
    ../Shared/StopTravel.cpp \
    ../Shared/Tile.cpp \
    ../Shared/Won.cpp \
    ServerOutputThread.cpp \
    ServerInputThread.cpp \
    CreateNetworkGame.cpp \
    ../Shared/CreateGame.cpp \
    ../Shared/Debug.cpp \
    ../Shared/Validation.cpp \
    ../Shared/YourIdPlayer.cpp \
    ../Shared/Quit.cpp


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
    DescriptionPlayersNetwork.h \
    PlayerWidget.h \
    TileWidget.h \
    ../Shared/Board.h \
    ../Shared/Card.h \
    ../Shared/Game.h \
    ../Shared/InitGame.h \
    ../Shared/IWantPlay.h \
    ../Shared/NewPlayerAdd.h \
    ../Shared/Pack.h \
    ../Shared/Packs.h \
    ../Shared/Pile.h \
    ../Shared/PilePlayer.h \
    ../Shared/PileTarget.h \
    ../Shared/PileWhenTravel.h \
    ../Shared/PlayedTile.h \
    ../Shared/PlayedTravel.h \
    ../Shared/Player.h \
    ../Shared/PlayTile.h \
    ../Shared/PlayTravel.h \
    ../Shared/Point.h \
    ../Shared/ProdCons.h \
    ../Shared/Profile.h \
    ../Shared/Square.h \
    ../Shared/StartedTravel.h \
    ../Shared/StartGame.h \
    ../Shared/StartTravel.h \
    ../Shared/Stop.h \
    ../Shared/StoppedTravel.h \
    ../Shared/StopTravel.h \
    ../Shared/Stroke.h \
    ../Shared/Tile.h \
    ../Shared/Utils.h \
    ../Shared/Won.h \
    ServerOutputThread.h \
    ServerInputThread.h \
    CreateNetworkGame.h \
    ../Shared/CreateGame.h \
    ../Shared/Debug.h \
    ../Shared/Validation.h \
    ../Shared/YourIdPlayer.h \
    ../Shared/Quit.h

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
    DescriptionPlayersNetwork.ui \
    PlayerWidget.ui \
    TileWidget.ui \
    CreateNetworkGame.ui

RESOURCES +=

OTHER_FILES += \
    ../Shared/Makefile
