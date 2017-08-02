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
    dialog2.cpp \
    skill.cpp \
    develop.cpp \
    help.cpp \
    welcome.cpp \
    introduce.cpp \
    name.cpp

HEADERS  += mainwindow.h \
    fileop.h \
    datastreamop.h \
    data.h \
    adventurewindow.h \
    sleep.h \
    random.h \
    dialog.h \
    dialog2.h \
    skill.h \
    develop.h \
    help.h \
    welcome.h \
    introduce.h \
    name.h

FORMS    += mainwindow.ui \
    adventurewindow.ui \
    dialog.ui \
    dialog2.ui \
    skill.ui \
    develop.ui \
    help.ui \
    welcome.ui \
    introduce.ui \
    name.ui

RESOURCES += \
    source.qrc
