#-------------------------------------------------
#
# Project created by QtCreator 2017-07-17T21:13:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SaltyPet
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fileop.cpp \
    data.cpp \
    adventurewindow.cpp

HEADERS  += mainwindow.h \
    fileop.h \
    datastreamop.h \
    data.h \
    adventurewindow.h

FORMS    += mainwindow.ui \
    adventurewindow.ui

RESOURCES += \
    source.qrc
