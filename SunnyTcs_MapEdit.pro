#-------------------------------------------------
#
# Project created by QtCreator 2018-07-13T08:29:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SunnyTcs_MapEdit
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mapview.cpp

HEADERS  += mainwindow.h \
    mapview.h

FORMS    += mainwindow.ui \
    mapview.ui

RESOURCES += \
    images.qrc
