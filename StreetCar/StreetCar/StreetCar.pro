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
  #  BoardWidget.cpp \
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
    ../Shared/Station.cpp \
    ../Shared/StoppedTravel.cpp \
    ../Shared/StopTravel.cpp \
    ../Shared/Tile.cpp \
    ../Shared/Won.cpp \
    ServerOutputThread.cpp \
    ServerInputThread.cpp \
    CreateNetworkGame.cpp \
    ChooseCards.cpp \
    ../Shared/CreateGame.cpp \
    ../Shared/Debug.cpp \
    ../Shared/Validation.cpp \
    ../Shared/YourIdPlayer.cpp \
    ../Shared/Quit.cpp \
    ../Shared/Goal.cpp \
    DeleteProfile.cpp \
    ../TestFrame/BoardView.cpp \
    ../TestFrame/CardWidget.cpp \
    ../TestFrame/GameWidget.cpp \
    ../TestFrame/HandWidget.cpp \
    ../TestFrame/StationWidget.cpp \
    ../TestFrame/TileLabel.cpp \
    ../TestFrame/UtilsGui.cpp \
    ../TestFrame/GoalCard.cpp



HEADERS  += MainWindow.h \
    MainMenu.h \
    NewLocalGame.h \
    ProfilMenu.h \
 #   BoardWidget.h \
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
    ../Shared/Station.h \
    ../Shared/StoppedTravel.h \
    ../Shared/StopTravel.h \
    ../Shared/Stroke.h \
    ../Shared/Tile.h \
    ../Shared/Utils.h \
    ../Shared/Won.h \
    ServerOutputThread.h \
    ServerInputThread.h \
    CreateNetworkGame.h \
    ChooseCards.h \
    ../Shared/CreateGame.h \
    ../Shared/Debug.h \
    ../Shared/Validation.h \
    ../Shared/YourIdPlayer.h \
    ../Shared/Quit.h \
    ../Shared/Goal.h \
    DeleteProfile.h \
    ../TestFrame/BoardView.h \
    ../TestFrame/CardWidget.h \
    ../TestFrame/GameWidget.h \
    ../TestFrame/HandWidget.h \
    ../TestFrame/StationWidget.h \
    ../TestFrame/TileLabel.h \
    ../TestFrame/UtilsGui.h \
    ../Shared/ParamThreadClient.h \
    ../TestFrame/GoalCard.h

FORMS    += MainWindow.ui \
    MainMenu.ui \
    NewLocalGame.ui \
    ProfilMenu.ui \
  #  Board.ui \
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
    CreateNetworkGame.ui \
    ChooseCards.ui \
    DeleteProfile.ui

RESOURCES += \
    ressources.qrc

OTHER_FILES += \
    ../Shared/Makefile \
    ../Shared/Board.o \
    ../Shared/Card.o \
    ../Shared/Game.o \
    ../Shared/InitGame.o \
    ../Shared/IWantPlay.o \
    ../Shared/NewPlayerAdd.o \
    ../Shared/Pile.o \
    ../Shared/PilePlayer.o \
    ../Shared/PileTarget.o \
    ../Shared/PileWhenTravel.o \
    ../Shared/PlayedTile.o \
    ../Shared/PlayedTravel.o \
    ../Shared/Player.o \
    ../Shared/PlayTile.o \
    ../Shared/PlayTravel.o \
    ../Shared/Profile.o \
    ../Shared/Square.o \
    ../Shared/StartedTravel.o \
    ../Shared/StartTravel.o \
    ../Shared/Stop.o \
    ../Shared/StoppedTravel.o \
    ../Shared/StopTravel.o \
    ../Shared/Tile.o \
    ../Shared/Won.o \
    ../Shared/Board.dep \
    ../Shared/Card.dep \
    ../Shared/Game.dep \
    ../Shared/InitGame.dep \
    ../Shared/IWantPlay.dep \
    ../Shared/NewPlayerAdd.dep \
    ../Shared/Pile.dep \
    ../Shared/PilePlayer.dep \
    ../Shared/PileTarget.dep \
    ../Shared/PileWhenTravel.dep \
    ../Shared/PlayedTile.dep \
    ../Shared/PlayedTravel.dep \
    ../Shared/Player.dep \
    ../Shared/PlayTile.dep \
    ../Shared/PlayTravel.dep \
    ../Shared/Profile.dep \
    ../Shared/Square.dep \
    ../Shared/StartedTravel.dep \
    ../Shared/StartTravel.dep \
    ../Shared/Stop.dep \
    ../Shared/StoppedTravel.dep \
    ../Shared/StopTravel.dep \
    ../Shared/Tile.dep \
    ../Shared/Won.dep
