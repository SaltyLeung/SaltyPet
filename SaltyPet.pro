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
    data1.cpp \
    data.cpp

HEADERS  += mainwindow.h \
    fileop.h \
    datastreamop.h \
    data1.h \
    data.h

FORMS    += mainwindow.ui

RESOURCES += \
    source.qrc
