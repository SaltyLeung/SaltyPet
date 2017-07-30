#-------------------------------------------------
#
# Project created by QtCreator 2017-07-17T21:13:10
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SaltyPet
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fileop.cpp \
    data.cpp \
    adventurewindow.cpp \
    sleep.cpp \
    dialog.cpp \
    dialog2.cpp

HEADERS  += mainwindow.h \
    fileop.h \
    datastreamop.h \
    data.h \
    adventurewindow.h \
    sleep.h \
    random.h \
    dialog.h \
    dialog2.h

FORMS    += mainwindow.ui \
    adventurewindow.ui \
    dialog.ui \
    dialog2.ui

RESOURCES += \
    source.qrc
