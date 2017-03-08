#-------------------------------------------------
#
# Project created by QtCreator 2017-02-22T03:48:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QProjectBatata
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    Batata.cpp \
    Game.cpp \
    Matrix.cpp \
    Monster.cpp \
    Movable.cpp \
    Obj.cpp \
    Obstacle.cpp \
    ObstacleM.cpp \
    Player.cpp \
    Position.cpp \
    lkqmatrix.cpp \
    qbatata.cpp \
    qgame.cpp \
    qmonster.cpp \
    qobj.cpp \
    qobstacle.cpp \
    qobstaclem.cpp \
    qplayer.cpp \
    qempty.cpp

HEADERS  += mainwindow.h \
    Batata.hpp \
    Game.hpp \
    Matrix.hpp \
    Monster.hpp \
    Movable.hpp \
    Obj.hpp \
    Obstacle.hpp \
    ObstacleM.hpp \
    Player.hpp \
    Position.hpp \
    EnumDirection.hpp \
    lkqmatrix.hpp \
    qbatata.hpp \
    qgame.hpp \
    qmonster.hpp \
    qobstacle.hpp \
    qobstaclem.hpp \
    qplayer.hpp \
    qobj.hpp \
    qempty.hpp

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    ressources.qrc

