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
    data.cpp \
    fileop.cpp

HEADERS  += mainwindow.h \
    data.h \
    fileop.h \
    datastreamop.h

FORMS    += mainwindow.ui

RESOURCES += \
    source.qrc
