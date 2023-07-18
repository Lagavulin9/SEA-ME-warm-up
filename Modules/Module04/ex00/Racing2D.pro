QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    game.cpp \
    gamescene.cpp \
    main.cpp \
    thread.cpp \
    view.cpp

HEADERS += \
    car.h \
    game.h \
    gamescene.h \
    thread.h \
    view.h

RESOURCES += \
    resource.qrc
